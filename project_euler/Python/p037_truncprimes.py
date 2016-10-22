
from datetime import datetime

###################################################################################################
# Sieve of Eratosthenes
# Code by David Eppstein, UC Irvine, 28 Feb 2002
# http://code.activestate.com/recipes/117119/

def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}  

    # The running integer that's checked for primeness
    q = 2  

    while True:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            # 
            yield q        
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next 
            # multiples of its witnesses to prepare for larger
            # numbers
            # 
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1

###################################################################################################
def isTruncPrime(pl,ip):
    if len(str(ip)) > 1:            # Cannot count 1-digit numbers
        fact = 10**(len(str(ip))-1) # Find maximum divisible number (i.e. - 9999 will cause 1000)
        if ((ip/fact) in [1,2,3,5,7,9]) and ((ip%10) in [1,2,3,5,7,9]):     # Will require 1,3,7,9 here. 1 & 9 are not primes, so exclude them.
            fwd = bwd = ip
            for i in xrange(len(str(ip))-1):
                fwd, bwd, fact = (fwd % fact), (bwd / 10), (fact/10)
                if (fwd not in pl) or (bwd not in pl):
                    break
            else:
                return True
    return False


start = datetime.now()

# Generate primes with only 1, 3, 7, 9 in them. No need to account for 2/5 because 1-digit primes will not count here
goodNums    = set(['1','2','3','5','7','9'])
good_filter = lambda x: not set(str(x)).difference(goodNums)

primes, count, tot = [], 0, 0
for i in gen_primes():
    primes.append(i)
    if not set(str(i)).difference(goodNums):
        if isTruncPrime(primes,i):
            tot   += i
            count += 1
            print count, i, tot
    if count >= 11:
    	break

print count, tot

print datetime.now()-start
