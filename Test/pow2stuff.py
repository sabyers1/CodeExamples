#pow2stuff.py

import math


def calcDigits(val):
    """Calculate the number of base -2 digits needed to represent value."""
    if a==0:
        return 0
    negNum = False
    if val < 0:
        negNum = True
        val = - val
    w=0
    for n in range(9):
        if negNum:
            w += 2**(2*n+1)
        else:
            w += 2**(2*n)

        if w >= val:
            if negNum:
                return 2*n+2
            return 2*n+1
    return 2*n+1  # returns 17 which is > 130K

def calcVector(val):
    bits = calcDigits(val)
    print("Base -2 digits required: {}".format(bits))
    v = [0] * (bits)  #initialize vector
    w = ws = 0      #weights and sum of weights
    for k in range(bits):
        w = (-2)**k  #power of -2 coefficient for vector coeffient
        ws += w      #sum of coefficients
        if k == 0:
            v[k] = val%2
        elif k%2 == 0: #even coeffients 0,2,4,6...
            step2 = ((val+ws-1)/abs(w))
            if -1.0 < step2 and step2 < 0.0 :
                step2 = -1
            v[k]  = int(step2%abs(w))%2
            #v[k] = (int((val+ws-1)/abs(w))%abs(w))%2
        else:        #odd coeffients 1,3,5...
            step2 = ((val+(ws-w)-1)/abs(w))
            if -1.0 < step2 and step2 < 0.0 :
                step2 = -1
            v[k]  = int(step2%abs(w))%2
            #print("  S1: {} S2: {} ".format(step1,step2))
            #v[k] = (int((val+(ws-w)-1)/abs(w))%abs(w))%2 #reduce sum of weights to use previous sum
            
        print("W: {:5} Ws: {:8} [{:2}] = {}".format(w,ws,k,v[k])) 
    return v

def calcValue(v):
    a = 0
    sz = len(v)
    if sz==0:
        return a
    
    for i in range(sz):
        a += v[i]*(-2)**i

    return a

done = False
while( not done):
    print("Enter value for digits ('q' to quit:) ", end="")
    a = input()
    if a.lower() == "q":
        done = True
    else:
        try:
            #d = calcDigits(int(a))
            #print("Base -2 digits required: {}".format(d))
            va=calcVector(int(a))
            t=calcValue(va)
            if int(a) != t:
                print("Wrong answer! {} != {}".format(a,t))
            else:
                print ("{} == {}".format(a,t))
        except Exception as e:
            print ("{} is not valid number.".format(a))
            print (e)    
        finally:
            pass

