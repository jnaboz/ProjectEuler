"""
It can be seen that the number, 125874, and its double, 251748,
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
"""
from datetime import datetime
import collections

def same_permutation(a, b):
    d = collections.defaultdict(int)
    for x in a:
        d[x] += 1
    for x in b:
        d[x] -= 1
    return not any(d.itervalues())

def checkpermutations(a,b):
    returnvalue = False
    if len(a) == len(b):
        if len(a) < 100:
            returnvalue = (sorted(a) == sorted(b))
        else:
            returnvalue = same_permutation(a, b)
    return returnvalue

def checkRpt(s):
    l = len(s)/10
    for c in s:
        cnt = s.count(c)
        if cnt > l: return False
    return True


def containAll(stst, sets):
    return 0 not in [c in stst for c in sets]

if __name__ == "__main__":
    st = datetime.now()

    found = False
    begin = 10
    while not found:
        for i in range(begin,((5*begin)/3)):
            ans = [i]
            for j in range(2,7):
                if checkpermutations(list(str(i)), list(str(i*j))):
                    ans.append(i*j)
                else:
                    break
            else:
                found = True
                break
        if not found:
            begin *= 10

    print ans[0]
    print "Answer in: " + str(datetime.now()-st)
