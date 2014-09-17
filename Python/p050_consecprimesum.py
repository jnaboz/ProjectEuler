
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

def consecprimes(val, offst):
    global primes
    for i in range(len(primes)-offst):
        tot = val
        consec = 0
        for j in range(i,len(primes)-offst):
            tot -= primes[j]
            consec += 1
            if tot == 0:
            	break
            if tot < 0:
            	consec = 0
            	break
        if consec > 0: break
    return consec




if __name__ == "__main__":
    st = datetime.now()

    limit = 1000000

    primes = []
    startsum = 0
    for p in gen_primes():
        if p < limit: primes.append(p)
        else: break

    tprimes = primes
    val, consec = 0, 0
    i, up = 0, len(tprimes)
    tval, tcnt = 0, 0
    while (i < up) and (up > consec):
        tval, tcnt, i = tval+tprimes[i], tcnt+1, i+1
        if (tval in primes) and (tcnt > consec):
            val, consec = tval, tcnt
        if tval > limit:
            tprimes.pop(0)
            i, up = 0, len(tprimes)
            tval, tcnt = 0, 0

    print val, consec
    print "Answer in " + str(datetime.now() - st)
