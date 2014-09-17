
from datetime import datetime

if __name__ == "__main__":
    st = datetime.now()

    tot = 0
    for a in range(1,100):
        for b in range(2,100):
            num = a**b
            tmp = sum([int(s) for s in str(num)])
            if tmp > tot: tot = tmp

    print tot
    print "Answer in: " + str(datetime.now()-st)
