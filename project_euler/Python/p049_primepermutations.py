
from datetime import datetime 
import itertools

def gen_primes():
    D = {}  
    q = 2  
    while True:
        if q not in D:
            yield q        
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1


def checkDiffs(il):
    diffs = list()
    if len(il) >= 3:
        for i in range(len(il)-1):
            for j in range(i+1,len(il)):
                tmp = il[j] - il[i]
                if ((il[j] + tmp) in il):
                    for x in [il[i], il[j], il[j]+tmp]:
                        if x not in diffs: diffs.append(x)
                    if len(diffs) != 3: diffs = []
    return diffs


if __name__ == "__main__":
    st = datetime.now()

    primes = []
    for p in gen_primes():
        if len(str(p)) > 4: break
        if len(str(p)) == 4: primes.append(p)

    ans = []
    cnt = 0
    for p in primes:
        if p > 0:
            if p not in ans:
                tst = sorted([x for x in map(int, map("".join, itertools.permutations(str(p)))) if x in primes])
                tmp = checkDiffs(tst)
                if len(tmp) == 3:
                    if tmp not in ans: ans.append(tmp)
            if cnt == 2:
                print "break"
                break

    print ans
    print "Answer in " + str(datetime.now() - st)
