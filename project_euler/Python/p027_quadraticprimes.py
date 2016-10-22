import datetime

def is_prime(num):
    rtn = True
    if num <= 1:
        rtn = False
    else:
        for x in range(2, int(num**0.5 + 1)):
            if num % x == 0:
                rtn = False
    return rtn

result = [0, 0]
starttime = datetime.datetime.now()
for b in range(-999,1000,2):
    if is_prime(b) == True:
        for a in range(-999,1000):
            n = 0
            while True:
                tmp = (n**2) + (a*n) + b
                if is_prime(tmp) == True:
                    n += 1
                else:
                    if n > result[1]:
                        result = [(a*b), n]
                    break
endtime = datetime.datetime.now()

print result
print endtime - starttime 
