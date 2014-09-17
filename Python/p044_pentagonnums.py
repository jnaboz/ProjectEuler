
from datetime import datetime


def genPentNums(ubound=0):
    if ubound == 0:
        n = 1
        while True:
            yield ((3*(n*n))-n) >> 1
            n += 1
    else:
        for n in range(1,ubound+1):
            yield ((3*(n*n))-n) >> 1


if __name__ == "__main__":
    st = datetime.now()

    limit = 5000
    pnums = [None]
    plims = [None]
    
    # Generate list of pentagonal numbers
    tmp = 1
    for pn in genPentNums(limit):
    	pnums.append(pn)
    	plims.append((tmp*3)+1)
    	tmp += 1

    # Find pentagonal pairs
    cont = True
    for j in range(1000,len(pnums)):
    	pj, lj = pnums[j], plims[j]
    	#rk = [x for x in range(2,len(plims)) if ((x != j) and (pj >= plims[x]) and (lj <= pnums[x]))]
    	rk = []
        for x in range(2,len(plims)):
            if (pj >= plims[x]):
                if ((x != j) and (lj <= pnums[x])):
                    rk.append(x)
            else: break

        for k in rk:
            pk = pnums[k]
            S,D = pj+pk, pk-pj
            if (S in set(pnums)) and (D in set(pnums)):
            	ans, cont = D, False
            	break
        if not cont: break
    else: ans = None

    print ans
    print datetime.now() - st






def euler44():
    ''' Pn=n(3n-1)/2 Find Pn1,Pn2,Pn3,Pn4 with Pn1+Pn2 = Pn3 and Pn1-Pn2 == Pn4
        From this follows: Pn3 > Pn1 > Pn2, Pn1 > Pn4, so use Pn3 to build a set
        of Pn's. By adding  Pn1+Pn2 = Pn3 and Pn1-Pn2 == Pn4 we get 2Pn1 = Pn3 + Pn4
        so Pn1 = (Pn3 + Pn4)/2 Pn2 is then Pn3 - Pn1
    '''
    
    penta_iter = (n*(3*n-1)/2 for n in count(1))
    penta_set = set()
    
    for Pn3 in penta_iter:
        penta_set.add(Pn3)
        for Pn4 in (x for x in penta_set if x < Pn3):
            Pn1 = 0.5 * (Pn3 + Pn4)
            if Pn1 in penta_set: 
                Pn2 = Pn3 - Pn1
                if Pn2 in penta_set: 
                    return int(Pn2)
