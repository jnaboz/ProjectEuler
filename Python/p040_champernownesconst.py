

from datetime import datetime
from operator import mul

st = datetime.now()

# First method - 0.191s
LIMIT  = 1000000
SAMPLE = 1
digits = []
i = 1
idx = 0
while SAMPLE <= LIMIT:
    digadd = len(str(i))
    tid    = idx + digadd
    if tid >= SAMPLE:
    	digits.append(int(str(i)[SAMPLE-idx-1]))
    	SAMPLE *= 10
    else:
    	pass
    idx, i = tid, i+1

print digits
print reduce(mul,digits,1)
print datetime.now() - st
print

# Second method - 0.162s
st = datetime.now()
s = ""
i = 1
while len(s) <= 1000000:
    s += str(i)
    i += 1
d = [int(s[1-1]),int(s[10-1]),int(s[100-1]),int(s[1000-1]),int(s[10000-1]),int(s[100000-1]),int(s[1000000-1])]
print d
print reduce(mul,d,1)
print datetime.now() - st
