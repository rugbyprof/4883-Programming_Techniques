import requests
import json
from rich import print
import datetime
import os
import sys


def getSubmissions():
    if os.path.isfile("./submissions.json"):
        mtime = os.path.getmtime("./submissions.json")
        print("mdatetime = {}".format(datetime.datetime.fromtimestamp(mtime)))
        # mdatetime = 2012-01-04 14:19:06.523398

    r = requests.get(
        "http://cs.msutexas.edu/uva/api/?route=classSubmissions", verify=False
    )
    with open("submissions.json", "w") as f:
        f.write(json.dump(r.json(), f, indent=4))


def loadProblems():
    with open("probs.json") as f:
        probs = json.load(f)
    return probs


def loadSubmissions():
    with open("submissions.json") as f:
        submissions = json.load(f)
    return submissions


if __name__ == "__main__":
    # getSubmissions()
    average = 0.0
    students = 0
    probs = loadProblems()
    submissions = loadSubmissions()
    results = []
    for name in list(submissions["data"].keys()):
        students += 1.0
        acceptedNums = []
        accepted = list(submissions["data"][name]["Accepted"].values())
        del accepted[-1]

        acceptedCount = 0
        expectedCount = 0
        for set in probs:
            expectedCount += set["count"]
            for num in set["probnums"]:
                for item in accepted:
                    if str(num) in item:
                        acceptedCount += 1

        average += acceptedCount
        print(
            f"{name}       \t{acceptedCount} {int(acceptedCount/expectedCount*100)}% {int(acceptedCount/15*100)}%"
        )
        first, last = name.split(",")
        print(last)
        results.append(
            f"{last},{first}      \t{acceptedCount} {int(acceptedCount/expectedCount*100)}% {int(acceptedCount/17*100)}%"
        )

        # for num1 in acceptedNums:
        #     for item in probs:
        #         for num2 in item["probnums"]:
        #             if int(num1) == int(num2):
        #                 print(True)

    print(sorted(results))
