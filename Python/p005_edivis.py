
myrange  = range(1,21)           # Numbers to be divisible by

def lcm(inlist):
    vals = list(inlist)
    newlcm = 1
    for val in vals:
    	multiply = 1
        while True:
            tmp = val * multiply
            if tmp <= newlcm:
                if newlcm % tmp == 0:   # Current LCM is divisible by new number
                    break
            else:
                if tmp % newlcm == 0:   # New number is divisible by current LCM
                    newlcm = tmp        # Update LCM
                    break
            multiply += 1
    return newlcm

print lcm(myrange)
