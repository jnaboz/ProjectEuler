
from datetime import datetime

if __name__ == "__main__":
    fin = "c:\\adrv\\zzother\\09. Learning\\Python\\Euler\\p059_cipher1.txt"
    fout = "c:\\adrv\\zzother\\09. Learning\\Python\\Euler\\p059_plaintext.txt"
    st = datetime.now()

    f = open(fin, 'r')
    text = map(int, f.readline().split(','))
    f.close()

    lowers = [i for i in range(ord('a'), ord('z')+1)]
    uppers = [i for i in range(ord('A'), ord('Z')+1)]

    f = open(fout, 'w')
    for c1 in lowers:
        for c2 in lowers:
            for c3 in lowers:
                plaintext = []
                tot = 0
            	passwd = [c1, c2, c3]
                for i in range(len(text)):
                    pt = text[i]^passwd[i%3]
                    plaintext.append(chr(pt))
                    tot += pt
                f.write(''.join(plaintext) + "\n")
                f.write(chr(c1) + chr(c2) + chr(c3) + " " + str(tot) + "\n\n")

    f.write("Answer in: " + str(datetime.now() - st))
    f.close
