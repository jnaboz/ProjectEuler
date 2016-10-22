
# Smallest possible = 123456789
# Largest possible  = 987654321

def ispandigital(a,b,c):
    x = str(a) + str(b) + str(c)
    y = sorted(x)
    tmp = ''.join(sorted(y))
    if tmp == "123456789": return True
    return False


test_str = "123456789"
products = []

for a in range(1,9999):
    for b in range(a,9999/a):
        if (ispandigital(a,b,(a*b))) and ((a*b) not in products):
            products.append((a*b))

mysum = 0
for prd in products:
    mysum += prd
print mysum
