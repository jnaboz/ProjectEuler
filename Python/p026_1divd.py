
maxlength = 0
maxnum    = 0
for i in range(1,1001,2):
    val = 1
    while i > val:
    	val *= 10

    divby = [val]
    while val % i != 0:
        val = (val % i) * 10
        if val in divby:
            if (len(divby) - divby.index(val)) > maxlength:
            	maxlength, maxnum = (len(divby) - divby.index(val)), i
            break
        else:
            divby.append(val)
    else:
    	pass

print maxnum, maxlength
