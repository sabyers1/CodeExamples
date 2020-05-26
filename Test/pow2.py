import math

a=3334 #0,1,0,1,1,0,0,0,1,0,1,1,1
bits = math.floor(math.log(2*a)/math.log(2))
bits2 = math.ceil(math.log2(2*a))

print("The bits are: {} or {} for {}".format(bits,bits2,a))
v = [0] * (bits2)
for k in range(bits2-1,-1,-1):
    w = (-2)**k
    print("W: {:3} ".format(w),end="")
    if  abs(a) > abs(a-w) :
        a =  a - w
        v[k]=1
        print("[{}] set+, new a = {:3}".format(k,a))
    #elif abs(a) >= abs(a-w):
    #    a-=w
    #    v[k]=1
    #    print("[{}] set-, new a = {:3}".format(k,a))
    else:
        print("[{}] clr       a = {:3}".format(k,a))
        
print(v)
#g=1*0 - 2*1 + 4*1 - 8*1 + 16*0 - 32*0 + 64*0 - 128*0 + 256*1 - 512*1 + 1024*1 - 2048*0 + 4096*1 - 8192*0
#print ("g: {}".format(g))
def calcV(v):
    a = 0
    sz = len(v)
    if sz==0:
        return a
    
    for i in range(sz):
        a += v[i]*(-2)**i

    return a

if a != calcV(v):
    print ("Wrong value!!")
print("v: {}".format(v))
print("v: {}".format(calcV(v)))