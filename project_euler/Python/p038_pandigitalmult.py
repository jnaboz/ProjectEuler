

from datetime import datetime


def isPandigital(s):
    y = sorted(s)
    tmp = ''.join(sorted(y))
    if tmp == "123456789": return True
    return False

def digCount(l):
    rtn = 0
    for item in l:
    	rtn += len(str(item))
    return rtn






st = datetime.now()

LIMIT = 987654321
v = 918273645
for i in range(13,10000,2):
    l = []
    j = 1
    while digCount(l) < 9:
        l.append(i*j)
        j += 1
    if digCount(l) == 9:
    	tmp = ""
        for item in l:
            tmp += str(item)
        if (isPandigital(tmp)) and (int(tmp) > v): v = int(tmp)
    if v == LIMIT: break

print v
print datetime.now() - st
