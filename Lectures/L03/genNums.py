import random
import math
import sys

def main(n,m=2**30):
    with open("rnums.dat","w") as f:
        f.write(str(n)+" ")
        for i in range(n):
            r = math.floor(random.random() * m)
            f.write(str(r)+" ")

if __name__=='__main__':
    if len(sys.argv) == 1:
        n = 10000
        m = 2**30
    elif len(sys.argv) == 2:
        n = int(sys.argv[1])
        m = 2**30
    elif len(sys.argv) == 3:
        n = int(sys.argv[1])
        m = int(sys.argv[2])

    main(n,m)

    print(2**30)