# How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100, are greater than one-million
from datetime import datetime
import itertools
import math

def nCr(n,r):
    num = math.factorial(n)
    den = math.factorial(r) * math.factorial(n-r)
    return (num/den)
    

if __name__ == "__main__":
    st = datetime.now() 

    ans = 0
    for n in range(23,101):
    	r = 1
    	tmp = 0
        while r < ((n/2)+1):
            if nCr(n,r) > 10**6:
                tmp += 1
            r += 1
        ans += (tmp*2)
        if (n%2) == 0: ans -= 1

    print ans
    print "Answer in: " + str(datetime.now()-st)
