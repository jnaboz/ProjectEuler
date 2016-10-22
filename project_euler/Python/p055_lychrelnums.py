
from datetime import datetime

def isPalindrome(n):
    return str(n)[::] == str(n)[::-1]

def isLychrel(n):
    tot = n
    for it in range(50):
    	fwd = tot
        bwd = int(str(fwd)[::-1])
        tot = fwd + bwd
        if isPalindrome(tot): return False
    return True

if __name__ == "__main__":
    st = datetime.now()

    cnt = 0
    for i in range(1,10000):
        if isLychrel(i): cnt += 1

    print cnt
    print "Answer in: " + str(datetime.now()-st)
