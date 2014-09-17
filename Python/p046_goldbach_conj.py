
from datetime import datetime

def gen_primes_tbl(ubound):
    isPrime = [True for i in range(0, ubound+1)]
    for i in range(2,int(ubound**0.5)+1):
        if not isPrime[i]: continue
        for j in range(i*i, ubound+1, i): isPrime[j] = False
    primes = []
    for i in range(2, len(isPrime)):
        if isPrime[i]: primes.append(i)
    return(primes)




if __name__ == "__main__":
    st = datetime.now()

    primes = gen_primes_tbl(10000)
    print "Primes in " + str(datetime.now() - st)

    i = 9
    cont = True
    while cont:
    	cont = False
        for p in primes:
            if p < i:
            	tst = (((float(i)-float(p))*0.5)**0.5)
            	if tst == int(tst):
            	    cont = True
            else: break
        if cont:
            i += 2
            while i in primes: i+=2
    print i
    print "Answer in " + str(datetime.now() - st)
