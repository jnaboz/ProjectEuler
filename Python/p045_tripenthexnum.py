
from datetime import datetime

def genTriNum():
    n = 285
    while True:
    	yield ((n*n)+n)>>1
    	n+=1

def genPentNum():
    n = 165
    while True:
    	yield ((3*(n*n))-n)>>1
    	n+=1

def genHexNum():
    n = 144
    while True:
    	yield ((2*(n*n))-n)
    	n+=1

def findNextTPHNum():
    n = 1
    while True:
    	n += 1
    	h = n*((2*n)-1)
    	k = (1.0+((1.0+(24.0*float(h)))**0.5))/6.0
        if k == int(k): yield h


if __name__ == "__main__":
    st = datetime.now()

    cnt = 0
    for i in findNextTPHNum():
    	print i
    	cnt += 1
        if cnt >= 3: break
    #rtn = 0
    #for h in genHexNum():
    #    for p in genPentNum():
    #        if p == h:
    #            for t in genTriNum():
    #                if t == p: rtn = t
    #                elif t > p: break
    #                else: pass
    #        elif p > h: break
    #        else: pass
    #        if rtn != 0: break
    #    if rtn != 0: break

    #print rtn
    print datetime.now() - st
