

from datetime import datetime

card_dict = {
    '2' : 2,
    '3' : 3,
    '4' : 4,
    '5' : 5,
    '6' : 6,
    '7' : 7,
    '8' : 8,
    '9' : 9,
    'T' : 10,
    'J' : 11,
    'Q' : 12,
    'K' : 13,
    'A' : 14
}

hand_dict = {       # Base value for hand combinations. Increment by power of 2 due to possible overflow.
    'HC'        : 10**0,
    'OP'        : 10**1,
    'TP'        : 10**2,
    'THREEOAK'  : 10**3,
    'STRAIGHT'  : 10**4,
    'FLUSH'     : 10**5,
    'FH'        : 10**6,
    'FOUROAK'   : 10**7,
    'STRTFLSH'  : 10**8,
    'ROYALFLSH' : 10**9
}


def two_cards(d, flush):    # Two different cards in hand (full house, four of a kind)
    global hand_dict
    hand = 0
    for key in d.keys():
        if d[key] == 4:
            hand = hand_dict['FOUROAK'] * key   # set base value for four of a kind
        elif d[key] == 3:
            hand = hand_dict['FH'] * key        # set base value for full house
        else:
            tmp = key                           # store other value for adding on to base value
    hand += tmp                                 # Add high card
    return hand


def three_cards(d, flush):  # Three different cards in hand (two pairs, three of a kind)
    global hand_dict
    ones = []
    twop = []
    hand = 0
    for key in d.keys():
        if d[key] == 2:
            twop.append(key)
        elif d[key] == 3:
            hand = hand_dict['THREEOAK'] * key          # Base value for three of a kind
        else:
            ones.append(key)
    if len(twop) > 0:
    	hand = hand_dict['TP'] * max(twop)              # Base value for highest pair in 2pairs
    	hand += ((hand_dict['TP'] / 10) * min(twop))    # Add sub-value for second pair @ 1/10 base value for 2pairs
    hand += max(ones)                                   # Add high card
    return hand

def four_cards(d, flush):   # Four different cards in hand (one pair)
    global hand_dict
    t = []
    hand = 0
    for key in d.keys():
        if d[key] == 2:
            hand = hand_dict['OP'] * key                # Base value for one pair multiplied by pair value
        else:
            t.append(key)
    hand += max(t)                                      # Add high card
    return hand

def five_cards(d, flush):   # Five different cards in hand (high card, flush, straight, straight flush, royal flush)
    global hand_dict
    hand = 0
    tmp = sorted([k for k in d.keys()])
    if (2 in tmp) and (14 in tmp):
        tmp[len(tmp)-1] = 1
        tmp = sorted(tmp)
    for i in range(len(tmp)-1):
        if tmp[i] == tmp[i+1]-1:    # check for increments by 1 (straight)
            continue
        else:                       # Hand is not a straight. High Card base value * max card value
            if (1 in tmp):
                tmp[0] = 14
                tmp   = sorted(tmp)
            hand  = hand_dict['HC'] if not flush else hand_dict['FLUSH']
            hand *= max(tmp)
            break
    else:
        # Found a straight. Hand is worth base straight (flush) * max card value
        mtmp = max(tmp)
        if flush:
            if mtmp == 14:
                hand = hand_dict['ROYALFLSH']
            else:
                hand = hand_dict['STRTFLSH']
                hand *= mtmp
        else:
            hand  = hand_dict['STRAIGHT']
            hand *= mtmp
    return hand

dtct_dict = {
    2 : two_cards,
    3 : three_cards,
    4 : four_cards,
    5 : five_cards
}

class Poker(object):
    def __init__(self,cards=[None,None,None,None,None],hand=None):
        self.cards = cards
        self.hand = hand

    def set_hand(self,cards=[None,None,None,None,None]):
        self.cards = cards

    def detect_hand(self):
        global card_dict, dtct_dict
        val, suit = [], []
        for card in self.cards:
            val.append(card_dict[card[0]])
            suit.append(card[1])

        # Detect Flush
        s = suit[0]
        flush = True
        for t in suit[1:]:
            if not (s == t):
            	flush = False
            	break

        # Detect Combinations
        cd = dict()
        for c in val:
            cd[c] = 1 if not c in cd.keys() else cd[c] + 1

        dlen = len(cd.keys())
        self.hand = dtct_dict[dlen](cd,flush)

    def __cmp__(self,other):
        return cmp(self.hand, other.hand)



if __name__ == "__main__":
    fin = "C:\\adrv\\zzother\\09. Learning\\Python\\Euler\\p054_poker.txt"
    st = datetime.now()

    games = []

    f = open(fin,"r")
    for line in f:
        game_cards = line.split()
        games.append(game_cards)
    f.close()

    p1wins = 0
    p1 = Poker()
    p2 = Poker()
    for game in games:
        p1.set_hand(game[:5])
        p2.set_hand(game[5:])
        p1.detect_hand()
        p2.detect_hand()
        if p1 > p2:
            p1wins += 1

    print p1wins
    print "Answer in: " + str(datetime.now()-st)
