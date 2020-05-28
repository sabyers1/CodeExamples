import math

def calcDigits(val):
    if val == 0 :
        return 0
    if val < 0:
        val = -val
        w=0
        for k in range(8):  # less than 100,000k
            w += 2**(2*k+1)
            if  w >= val:
                print ("k-: {} w: {:4} val:{:4} ".format(k,w,val))
                return 2*(k+1)
    else :
        w=0
        for k in range(8):
            w += 2**(2*k)
            if w >= val:
                print("k+: {} w: {:4} val:{:4}".format(k,w,val))
                return (2*k)+1

    return 17 # 2**17 ~ 131,000


a=-3334 #0,1,0,1,1,0,0,0,1,0,1,1,1
#a=-28 #0,0,1,0,0,1
aSave=a
#bits = math.floor(math.log(2*a)/math.log(2))
bits2 = calcDigits(a)

print("Need {} bits to represent {}".format(bits2,a))
v = [0] * (bits2)
for k in range(bits2-1,-1,-1):
    w = (-2)**k
    print("W: {:5} ".format(w),end="")
    if  abs(a%w) >= abs(a-w) :
        a -= w
        v[k]=1
        print("[{:2}] set+, new a = {:3}".format(k,a))
    #elif abs(a) >= abs(a-w):
    #    a-=w
    #    v[k]=1
    #    print("[{}] set-, new a = {:3}".format(k,a))
    else:
        print("[{:2}] clr       a = {:3}".format(k,a))
        
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

if aSave != calcV(v):
    print ("Wrong value!!")
else:
    print ("Correct value!!")
print("v2: {}".format(v))
print("vx: {}".format(calcV(v)))