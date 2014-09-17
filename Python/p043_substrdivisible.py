
from datetime import datetime
import itertools

tst = '1406357289'

def meetsReq(s):
    if ( \
            ((int(s[1:4]) % 2) == 0) and \
            ((int(s[2:5]) % 3) == 0) and \
            ((int(s[3:6]) % 5) == 0) and \
            ((int(s[4:7]) % 7) == 0) and \
            ((int(s[5:8]) % 11) == 0) and \
            ((int(s[6:9]) % 13) == 0) and \
            ((int(s[7:10]) % 17) == 0) \
        ): return True
    return False

st = datetime.now()
print sum([int(num) for num in map("".join, itertools.permutations(tst)) if meetsReq(num)]) # generate permutations for i-digits
print datetime.now() - st
