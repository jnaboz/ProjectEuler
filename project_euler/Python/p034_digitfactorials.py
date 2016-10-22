
import math

df = []
for i in range(3,1000000):
    digits = []
    tmp = i
    for x in range(len(str(i))):
        digits.append(tmp%10)
        tmp = tmp / 10
    tot = 0
    for digit in digits:
        tot += math.factorial(digit)
    if tot == i:
        df.append(i)

print df
tot = 0
for f in df:
    tot += f
print tot
