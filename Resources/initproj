#!/usr/local/bin/python3
"""Uva Project Initializer

"""

import sys
import os

from rich import print
from requests import get
from requests import request
from shutil import copyfile
from bs4 import BeautifulSoup


class UvaProject:
    def __init__(self, **kwargs):
        # pull keyword args out of kwargs
        self.template = kwargs.get("template", "./template/template.cpp")
        self.saveFolder = kwargs.get("saveFolder", "./")
        self.num = kwargs.get("num", None)
        self.saveFolderNum = os.path.join(self.saveFolder, str(self.num))

        # Get required parameters to ensure we have everything to run
        if self.num == None:
            print(f"Error: Need a problem number!")

        if not os.path.exists(self.template):
            print(f"Error: Template file - {self.template} doesn't seem to exist!")

        if not os.path.exists(self.saveFolder):
            print(f"Error: Output Folder - {self.saveFolder} doesn't seem to exist!")

        if os.path.exists(self.saveFolderNum):
            print(f"Output Folder - {self.saveFolderNum} already exists!")
            ans = input("Continue? [Y/n]")
            if ans == "n" or ans == "N":
                sys.exit()

        self.pid = self.uvHunt(self.num)

        # run the driver
        self.go()

    def go(self):
        self.createFolderTemplate()  # create folder for project
        self.getPdf()  # download pdf into folder
        self.saveUdebugFiles()  # go get uDebug files and copy to folder
        self.createReadme()  # create a readme file.

    def uvHunt(self, num):
        """Gets uvHunt info about a problem so we can get the problem id

        Args:
            num (int): Uva problem number

        Returns:
            int: uva problem id
        """
        r = get(f"https://uhunt.onlinejudge.org/api/p/num/{num}")
        data = r.json()
        return data["pid"]

    def createFolderTemplate(self):
        """This method creates a folder for the uva problem if it doesn't exist

        Args:
            num (int): The uva problem number
        """

        if not os.path.exists(self.saveFolderNum):
            print(f"Creating folder: {self.saveFolderNum}")
            os.makedirs(self.saveFolderNum)

        targetFile = os.path.join(self.saveFolderNum, "main.cpp")

        if not os.path.exists(targetFile):
            print(f"Copying file: {self.template} {targetFile}")
            copyfile(self.template, targetFile)
        else:
            print(f"A main.cpp file exists in target folder. Skipping copy ...")

    def getPdf(self):
        """Download problem pdf to local folder

        Args:
            num (int): problem number
        """
        # call my own api to grab pdf link
        response = get(
            f"https://cs.msutexas.edu/uva/api/?route=problemPdf&num={self.num}"
        )
        info = response.json()

        # pull pdf url out of api response
        pdfUrl = info["data"]["pdf_url"]

        response2 = get(pdfUrl)

        savePath = os.path.join(self.saveFolderNum, f"{str(self.num)}.pdf")
        print(f"Saving pdf to: {savePath}")
        with open(savePath, "wb") as f:
            f.write(response2.content)

    def getUdebugDataIds(self):
        """Get uDebug data id's, or the html integer values in the html so I can
            use their own servers to send me the debug data.

        Returns:
            list: Integer data ids
        """
        URL = f"https://www.udebug.com/UVa/{self.num}"
        page = get(URL)
        soup = BeautifulSoup(page.content, "html.parser")
        result = soup.find("div", class_="select_input_table")
        links = result.findAll("a", class_="input_desc")

        dataIds = []
        for link in links:
            if not link["data-id"] in dataIds:
                dataIds.append(link["data-id"])

        return dataIds

    def getUdebugData(self, dataId):
        """Download the uDebug file data from uDebug.

        Args:
            dataId (int): integer value uDebug uses to store each debug file on their server

        Returns:
            string: debug file data
        """
        url = "https://www.udebug.com/udebug-custom-get-selected-input-ajax"

        payload = {"input_nid": str(dataId)}
        files = []
        headers = {}
        response = request("POST", url, headers=headers, data=payload, files=files)
        data = response.json()
        return data["input_value"]

    def saveUdebugFiles(self):
        """Go to uDebug and download a specific debug file"""
        print("Getting uDebug data files...")
        dataIds = self.getUdebugDataIds()

        print(f"Found {len(dataIds)} files...")
        i = 1
        for did in dataIds:
            data = self.getUdebugData(did)
            saveTarget = os.path.join(self.saveFolderNum, f"in{i}")
            print(f"Saving {saveTarget} ...")
            with open(saveTarget, "w") as f:
                f.write(data)
            i += 1

    def createReadme(self):
        """Generate a readme file for the project as well."""
        print("Creating README.md ... ")
        url = f"https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem={self.pid}"
        saveTarget = os.path.join(self.saveFolderNum, "README.md")
        with open(saveTarget, "w") as f:
            f.write(f"## Problem {self.num}\n\n")
            f.write(f"- {url}\n")
            f.write(f"- https://www.udebug.com/UVa/{self.num}\n")


def usage():
    print("Usage: initproj 112 ")
    sys.exit()


if __name__ == "__main__":
    argv = sys.argv[1:]

    # make sure you added the problem number as a param
    if len(argv) == 0:
        usage()

    # grab problem number from command line
    problemNum = sys.argv[1]

    # num = The Uva problem number.
    # template = Location of cpp file you use as a peoject skeleton / template
    # saveFolder = A path where you want to save project folder. Remove this param to save in current folder.

    # pass in key value params to init UvaProject class
    proj = UvaProject(
        num=problemNum, saveFolder="./InProgress/", template="./template/template.cpp"
    )
