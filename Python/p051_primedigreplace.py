
"""

NOTE THAT THIS ALGORITHM IS NOT COMPLETE AND DOES NOT WORK
AS INTENDED. PREVIOUS WORKING ALGORITHMS TOOK WAY TOO LONG

"""

from datetime import datetime 

def fillPat(pat,num):
    filled = []
    filled.extend(pat)
    tmp = num
    for i in range(len(pat)-1,-1,-1):
        if not pat[i]:
            filled[i] = (tmp % 10)
            tmp = (tmp/10)
        else:
            filled[i] = -1
    return filled

def genNum(repNum, filledptrn):
    tmp = 0
    for i in range(len(filledptrn)):
    	tmp *= 10
    	tmp += repNum if filledptrn[i] == -1 else filledptrn[i]
    return tmp

def familySize(repeatNum, pattern):
    size = 1
    for i in range(repeatNum+1, 10):
        if (isPrime(genNum(i,pattern))): size += 1
    return size

def isPrime(n):
   """Returns True if n is prime"""
   if n == 2: return True
   if n == 3: return True
   if n % 2 == 0: return False
   if n % 3 == 0: return False
   i = 5
   w = 2
   while i * i <= n:
      if n % i == 0:
         return False
      i += w
      w = 6 - w
   return True


if __name__ == "__main__":
    st = datetime.now()

    fiveDigPat = [[False,True,True,True,False],
                  [True,False,True,True,False],
                  [True,True,False,True,False],
                  [True,True,True,False,False]]
    sixDigPat  = [[False,False,True,True,True,False],
                  [False,True,False,True,True,False],
                  [False,True,True,False,True,False],
                  [False,True,True,True,False,False],
                  [True,False,False,True,True,False],
                  [True,False,True,False,True,False],
                  [True,False,True,True,False,False],
                  [True,True,False,False,True,False],
                  [True,True,False,True,False,False],
                  [True,True,True,False,False,False]]

    result = 9999999
    for num in range(11,1000,2):
        if ((num % 5) == 0): continue
        ptrn = fiveDigPat if (num < 100) else sixDigPat
        for j in range(len(ptrn)):
            for k in range(3):
                if (ptrn[j][0] == 0) and (k == 0): continue
                fp = fillPat(ptrn[j],num)
                candidate = genNum(k,fp)
                if (candidate < result) and (isPrime(candidate)):
                    if familySize(k,fp) == 8:
                    	print candidate, familySize(k,fp)
                    	result = candidate
                    break

    print
    print result
    print "Answer in " + str(datetime.now() - st)
