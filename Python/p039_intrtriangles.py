

from datetime import datetime


def canMakeTriangle(a,b,c):
    if ((a+b)>c) and ((a+c)>b) and ((b+c)>a): return True
    return False

def isRightTriangle(a,b,c):
    hy = max(a,b,c)
    ss = [a,b,c]
    ss = filter(lambda a: a != hy, ss)
    lhs = 0
    for s in ss: lhs += (s**2)
    if lhs == (hy**2): return True
    return False


st = datetime.now()

fp = 0      # final answer
max_sol = 0 # max solution counter
fl = []
for p in range(100,1000,2):
    t = 0   # temp solution counter
    l = []
    for a in range(1,((p-1)/2)):
        for b in range(1,((p-a)/2)):
            c = p-a-b
            if canMakeTriangle(a,b,c):
                if isRightTriangle(a,b,c):
                    if sorted([a,b,c]) not in l:
                        t += 1
                        l.append([a,b,c])
    if t > max_sol:
    	max_sol, fp = t, p
    	fl = l

print max_sol, fp
print fl
print datetime.now() - st
