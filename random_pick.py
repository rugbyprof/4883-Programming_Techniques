import json
from random import shuffle,randint
from time import sleep
import os

with open("./.trunk/users.json") as f:
    data = json.loads(f.read())

r = randint(200,600)
for i in range(r):
    os.system('cls' if os.name == 'nt' else 'clear')
    print("\n\n\n\n\n\n\n\n\n\n")
    shuffle(data)
    sleep(.01)
    print(f"        {data[0]['name']}")
print("\n\n\n\n\n\n\n\n\n\n")