
from datetime import datetime


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


def primeFactors(val):
    global primes
    rtn = 0
    for p in primes:
        if p > val: break
        elif (val%p) == 0:
            val /= p
            rtn += 1
        else: pass
    return rtn



if __name__ == "__main__":
    st = datetime.now()

    primes = []
    for p in gen_primes():
        if p < 10000: primes.append(p)
        else: break
    print "Primes in " + str(datetime.now() - st)

    consec = 0
    i = 1000
    while True:
        if primeFactors(i) == 4: consec += 1
        else: consec = 0
        if consec == 4: break
        i+=1

    print i-3
    print "Answer in " + str(datetime.now() - st)
