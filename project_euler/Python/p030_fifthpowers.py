from datetime import datetime

st = datetime.now()
result = [i for i in range(2,1000000) if sum([int(j)**5 for j in str(i)]) == i]
print sum(result)
print result
print datetime.now() - st
