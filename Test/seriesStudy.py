import math

def calcDigits(val):
    if val == 0 :
        return 0
    val = abs(val)
    w=0
    for k in range(8):  # less than 100,000k
        w += 2**(2*k+1)
        if  w >= val:
            print ("k: {} w: {:4} val:{:4} ".format(k,w,val),end="")
            return 2*(k+1)
    return 17

    #return int(math.ceil(math.log2(abs(a))))+1

def calDigit2(val):
    val = abs(val)
    d = (math.log2(val*math.log(2))-1)/2
    return 2**d

for a in ((-2)**(2*i+1) for i in range(5)):
    d = calcDigits(a)
    print("{:4}  {}".format(a,d))

for a in (-41,-42,-43):
    d = calcDigits(a) 
    print("{:4}  {} == {}".format(a,d,calDigit2(a)))
