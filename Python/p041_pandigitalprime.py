
from datetime import datetime
import itertools

# find largest n-digit pandigital prime

def isPrime(val):
    if val == 2: return True
    if ((val % 2) == 0) or (val <= 1): return False
    for d in range(3,int((val**0.5))+1,2):
    	if ((val % d) == 0): return False
    return True


st = datetime.now()

# Keep divisibility rules in mind. All 8- and 9-digit pandigital numbers are divisible by 3
# Counting backwards reduces time significantly
f = 0
tmp = "7654321"
for i in range(7,0,-1):
    l = map("".join, itertools.permutations(tmp)) # generate permutations for i-digits
    for num in sorted(l,reverse=True): # Check in descending order
    	print num
        if (isPrime(int(num))) and (int(num) > f):
            f = int(num)
            break       # break from current permutation list
    if f != 0: break    # break from search since largest pandigital prime was found
    tmp = tmp[1:] # If, for whatever reason, a prime isn't found, then remove a digit and continue

print f
print datetime.now() - st

