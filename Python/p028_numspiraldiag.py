import datetime

actions_dict = {
        'r' :   { "roff" : 1,               # Row Offset
                  "coff" : 0,               # Col Offset
                  "tact" : (1, 0, 'd'),     # TRUE  (Row, Col, Direction)
                  "fact" : (0, 1, 'r')      # FALSE (Row, Col, Direction)
                },
        'd' :   { "roff" : 0,
                  "coff" : -1,
                  "tact" : (0, -1, 'l'),
                  "fact" : (1, 0, 'd')
                },
        'l' :   { "roff" : -1,
                  "coff" : 0,
                  "tact" : (-1, 0, 'u'),
                  "fact" : (0, -1, 'l')
                },
        'u' :   { "roff" : 0,
                  "coff" : 1,
                  "tact" : (0, 1, 'r'),
                  "fact" : (-1, 0, 'u')
                }
        }
"""
" loc used to tell current direction
" 0 : RIGHT
" 1 : DOWN
" 2 : LEFT
" 3 : UP
"""
def genSquare(length, width):
    global actions_dict
    rtn = [[0] * width for i in range(length)]  # Create list of 0's

    # Find middle and set to 1, go to right for next num
    row = length/2      # Find middle row
    col = width/2       # Find middle col
    rtn[row][col] = 1   # Set middle location to 1
    col += 1            # Move to right
    num = 2             # Init number to 2
    loc = 'r'           # Initial direction is RIGHT

    while num != ((length*width)+1):    # While still numbers to add
        rtn[row][col] = num             # Set next number
        num += 1                        # Increment number
        # Move to next cell based on dictionary offsets
        if rtn[row + actions_dict[loc]["roff"]][col + actions_dict[loc]["coff"]] == 0:
            tmp_roff, tmp_coff, loc = actions_dict[loc]["tact"]
            row, col = row+tmp_roff, col+tmp_coff
        else:
            tmp_roff, tmp_coff, loc = actions_dict[loc]["fact"]
            row, col = row+tmp_roff, col+tmp_coff
    return rtn

def getSqDiagSum(inlist):
    tot = 0
    nrows = len(inlist)
    col = 0
    for row in range(nrows):
        tot += inlist[row][col]
        col+=1
    col = 0
    for row in range(nrows-1,-1,-1):
        tot += inlist[row][col]
        col+=1
    tot -= 1
    return tot

starttime = datetime.datetime.now()
print getSqDiagSum(genSquare(1001,1001))
print datetime.datetime.now() - starttime


starttime = datetime.datetime.now()
total = 1
for i in range(3, 1002, 2): total += ((4*(i**2)) - (6*i) + 6)
print total
print datetime.datetime.now() - starttime
