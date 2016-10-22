import datetime

st = datetime.datetime.now()
print len({a**b for a in range(2,101) for b in range(2,101)})
print datetime.datetime.now() - st
