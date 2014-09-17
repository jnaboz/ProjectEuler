
coin_dict = {
#   coin : max
    200 : 1,
    100 : 2,
    50  : 4,
    20  : 10,
    10  : 20,
    5   : 40,
    2   : 100,
    1   : 200
}
limit = 200

def coin_combos(limit):
    if limit == 0: return 1
    if (limit < 0): return 0
    #coins.sort(reverse=True)    # Sort coin list in descending order (larger coins first)
    #combos = 0                  # Initialize combination counter
    #for coin in coins:          # Loop through all coins, high to low
    #	print coin
    #    if coin == limit: combos += 1
    #    else:
    #        pass
    #return combos

    # Account for easy combos. 200p, 2x100p
    combos = 2
    for b in range(limit/100):
        for c in range((limit/50)+1):
            for d in range((limit/20)+1):
                for e in range((limit/10)+1):
                    for f in range((limit/5)+1):
                        for g in range((limit/2)+1):
                            for h in range((limit/1)+1):
                                temp = ((100*b)+(50*c)+(20*d)+(10*e)+(5*f)+(2*g)+(1*h))
                                if temp == limit:
                                    combos += 1
                                elif temp > limit:
                                    break
    return(combos)


print
print coin_combos(limit), "coin combinations"
print
