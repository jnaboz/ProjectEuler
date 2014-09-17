
fractions = []
for num in range(10,100):
    for den in range(num+1,100):
    	nl = int(num/10)
    	nr = num % 10
    	dl = int(den/10)
    	dr = den % 10
    	q  = float(num)/float(den)
    	qlr = 0
    	qrl = 0
        if (dr != 0):
            qlr = float(nl)/float(dr)
        if (dl != 0):
            qrl = float(nr)/float(dl)
    	
        if (nr == dl) and (q == qlr):  # if reduced fraction is right/left canceling...
            fractions.append(q)
        elif (nl == dr) and (q == qrl):  # if reduced fraction is left/right canceling...
            fractions.append(q)
        else:   # Doesn't match like this...
            pass

if len(fractions) == 4:
    print fractions
    prd = 1
    for f in fractions:
    	prd *= f
    print prd
else:
    print "THE FRACTION COUNT IS NOT CORRECT\n"
