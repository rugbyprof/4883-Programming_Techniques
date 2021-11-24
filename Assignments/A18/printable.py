import json
from rich import print

with open("problems.json") as f:
    data = json.loads(f.read())

for k,v in data.items():
    print("- 📁",k)
    for item in v:
        key = list(item.keys())[0]
        print("   - [ ] 📄",key,item[key])