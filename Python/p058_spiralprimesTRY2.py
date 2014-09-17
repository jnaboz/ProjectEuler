
from datetime import datetime

def isPrime(val):
    if val == 2: return True
    if ((val % 2) == 0) or (val <= 1): return False
    for d in range(3,int((val**0.5))+1,2):
    	if ((val % d) == 0): return False
    return True

if __name__ == "__main__":
    st = datetime.now()

    found  = False

    nums   = 1
    primes = 0
    val    = 1
    sides  = 1
    inc    = 0
    while not found:
    	inc     += 2
    	sides   += 2
        newvals  = []
        for i in range(4):
            val  += inc
            nums += 1
            if isPrime(val): primes += 1
            if ((float(primes)/float(nums)) < 0.1):
                found = True

    print sides
    print "Answer in: " + str(datetime.now()-st)
