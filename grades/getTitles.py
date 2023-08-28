import json
import requests
from rich import print

with open("probs2.json") as f:
    data = json.load(f)

for assignment, nums in data.items():
    for num in nums["probnums"]:
        url = f"https://cs.msutexas.edu/uva/api/?route=infoByProbNum&num={num}"
        print(url)
        r = requests.get(url, verify=False)
        res = r.json()
        print(res["data"]["title"])
