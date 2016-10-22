
from datetime import datetime 


if __name__ == "__main__":
    st = datetime.now()

    print str(sum(i**i for i in range(1,1001)))[-10:]

    print "Answer in " + str(datetime.now() - st)
