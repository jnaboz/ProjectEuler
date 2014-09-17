
from datetime import datetime

st = datetime.now()
print sum([i for i in xrange(1000000) if ((str(i) == str(i)[::-1]) and ((str(bin(i))[2::]) == ((str(bin(i))[2::])[::-1])))])
print datetime.now() - st
