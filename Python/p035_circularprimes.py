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

def lshift(l,n):
    return l[n:]+l[:n]

def testCircular(n):
    global plist
    global outlist
    test_prime = plist[n]
    if (test_prime not in outlist) and (not set(str(test_prime)).difference(set(['1','3','7','9']))):                      # Prime is already found to be circular
        circ       = True
        tmp_list   = [test_prime]                   # Array of circular primes
        tstlen     = len(str(test_prime))

        if tstlen > 1:
            for x in xrange(1,tstlen):
            	temp = test_prime
            	test_prime = ((temp*10)%10**tstlen)+(temp/10**(tstlen-1))

                if((test_prime%10) in [1,3,7,9]):
                    if (test_prime in plist):               # If new value is a valid prime
                        if (test_prime not in tmp_list):   # Do not duplicate values
                            tmp_list.append(test_prime)
                    else:                               # Not a prime
                        circ = False
                        break
                else:
                    circ = False
                    break
        # Valid circular primes found
        if circ == True:
            for val in tmp_list:
                if val not in outlist:
                    outlist.add(val)
    else:
    	pass

st = datetime.now()

# Optimization could be made by removing as many primes as possible.
# Note that all primes must end in 1, 3, 7, 9 to be circular (since ending in an even number or 5 would no longer be prime)
# Thus, remove anything that contains digits outside of those.
pmax = 1000000
plist = gen_primes_tbl(1000000)
##### filter bad primes
####goodNums=set(['1','3','7','9'])
####good_filter=lambda x: not set(str(x)).difference(goodNums)
####plist=filter(good_filter,gen_primes_tbl(1000000))
    
outlist = set()

print "primes generated in " + str((datetime.now() - st))

for i in xrange(len(plist)):
    testCircular(i)
print len(outlist) + 2
print sorted(outlist)
print "circulars detected in " + str(datetime.now() - st)
