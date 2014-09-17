
from datetime import datetime
from fractions import Fraction
#import sys

# ISSUE since recursion limit isn't high enough. Also, the float number will get cut off
#def sqrt2conv(count,iterations):
#    if count >= iterations:
#    	return 0.0
#    else:
#    	return (1.0 / (2.0 + sqrt2conv(count+1,iterations)))

if __name__ == "__main__":
    #sys.setrecursionlimit(10000)
    st = datetime.now()
    cnt = 0

    # TRY #1
    #for i in range(1,10):
    #    dec = 1.0 + sqrt2conv(0,i)
    #    f   = Fraction(str(dec)).limit_denominator()
    #    fl  = str(f).split('/')
    #    num, den = fl[0], fl[1]
    #    if len(num) > len(den):
    #        print num,den
    #        cnt += 1

    # TRY #2
    NUM, DEN = 0, 1
    fracts = [None,[1,2],[5,2]]
    ans = [None,[3,2],[7,5]]
    for i in range(3,1001):
    	n = fracts[i-1][NUM]    # Get previous fraction
    	d = fracts[i-1][DEN]    # Get previous fraction
        n, d = ((2*n)+d), n     # Calculate next fraction
        fracts.append([n,d])    # Append to fractions list
        anum = n + d
        ans.append([anum,n])            # Append to answers list

    for a in ans[1:]:
        if len(str(a[NUM])) > len(str(a[DEN])):
            cnt += 1


    print cnt
    print "Answer in: " + str(datetime.now()-st)
