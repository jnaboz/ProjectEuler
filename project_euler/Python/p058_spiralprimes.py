
from datetime import datetime

def isPrime(val):
    if val == 2: return True
    if ((val % 2) == 0) or (val <= 1): return False
    for d in range(3,int((val**0.5))+1,2):
    	if ((val % d) == 0): return False
    return True

def genSpiralTable(lside):
    if lside%2 == 0: return None        # Side length must be odd
    tbl = [[None for j in range(lside)] for i in range(lside)]
    MAX = lside*lside
    row, col = lside-1, lside-1
    rub, cub = lside-1, lside-1
    rlb, clb = 0, 0
    cubchg   = False
    while MAX > 0:
        tbl[row][col] = MAX
        MAX -= 1
        if (row == rub) and (col > clb):   # Bottom side
            col -= 1
            if (col == (cub-1)) and cubchg:
            	cub -= 1
            	rlb += 1
            	cubchg = False
        elif (row > rlb) and (col == clb):    # Left side
            row -= 1
        elif (row == rlb) and (col < cub):   # Top side
            if col == clb:
            	rub -= 1            # If top left corner, reduce row amount since bottom row is done
            col += 1
        elif (col == cub) and (row < rub):  # Right side
            if row == rlb:
            	clb += 1
            row += 1
            cubchg = True
        else:
            pass    # invalid
    return tbl

def addLayer(tbl):
    # Add top and bottom rows
    tbl.insert(0,[None for i in range(len(tbl))])
    tbl.append([None for i in range(len(tbl))])

    row = len(tbl)-2    # Start with last filled row
    col = len(tbl[0])-1 # Start with last filled col
    val = tbl[row][col] + 1
    col += 1

    while row >= 0:                         # Append to right side of table
    	tbl[row].append(val)
    	val += 1
    	row -= 1
    row = 0
    col -= 1
    while col >= 0:                         # Fill in the empty top row
    	tbl[row][col] = val
    	val += 1
    	col -= 1
    col = 0
    while row < len(tbl):                   # Insert to left side of table
        tbl[row].insert(col,val)
        val += 1
        row += 1
    row = len(tbl)-1
    col += 1
    while col < len(tbl[row]):              # Fill in the empty bottom row
    	tbl[row][col] = val
    	val += 1
    	col += 1





if __name__ == "__main__":
    st = datetime.now()

####################
# Initialize and generate first table
####################
    found = False
    i = 5
    tbl = genSpiralTable(i)
    sidelen = len(tbl)

############################
# Create initial set of diag primes/vals
############################
    nums = set()
    primes = set()

    # top-left to bottom-right
    row = 0
    for col in range(sidelen):
    	val = tbl[row][col]
        if val not in nums: nums.add(val)
        if isPrime(val): 
            if val not in primes: primes.add(val)
        row += 1

    # bottom-left to top-right
    row = sidelen-1
    for col in range(sidelen):
    	val = tbl[row][col]
        if val not in nums: nums.add(val)
        if isPrime(val): 
            if val not in primes: primes.add(val)
        row -= 1


###########################
# Append layers until < 10% primes found
###########################
    while not found:
    	i += 2
    	addLayer(tbl)
    	lastidx = len(tbl)-1
    	newvals = [tbl[0][0], tbl[0][lastidx], tbl[lastidx][0], tbl[lastidx][lastidx]]
        for v in newvals:
            nums.add(v)
            if isPrime(v): primes.add(v)
        totnums = len(nums)
        totprim = len(primes)
        pct = float(totprim) / float(totnums)
        #print i, pct
        if pct < 0.1:
            found = True

    print i
    print "Answer in: " + str(datetime.now()-st)
