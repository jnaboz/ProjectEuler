
from datetime import datetime, timedelta

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

if __name__ == "__main__":
    st       = datetime.now()
    END_TIME = st + timedelta(minutes=1)

    num    = 0
    primes = []
    for p in gen_primes():
    	primes.append(p)
    	num += 1
        if num > 10000: break
    primes.pop(0)

    found    = False
    while ((datetime.now() < END_TIME) and (not found)):
    	pass

    print "Answer found in: " + str(datetime.now() - st)
