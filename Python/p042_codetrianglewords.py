
from datetime import datetime
import re


def genTriNums(ubound):
    for i in range(ubound):
        yield (0.5 * i * (i + 1))



def genWordVals():
    sif = "C:\\adrv\zzother\\09. Learning\\Python\\Euler\\p042_words.txt"
    f = open(sif,'r')
    ary = f.readline().replace('"','').split(',')
    for wrd in ary:
    	rtn = 0
        for ltr in wrd.upper(): rtn += (ord(ltr)-ord('A')+1)
        yield rtn
    f.close()


st = datetime.now()

trinums = set()
for trinum in genTriNums(1000):
    trinums.add(trinum)

cnt = 0
for word in genWordVals():
    if word in trinums: cnt += 1

print cnt
print datetime.now() - st
