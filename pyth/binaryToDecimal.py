def toBinary(num):
    arr=[0]*8
    i=-1
    while num:
        x=num & 1
        if x:
            try:
                arr[i]=1
            except IndexError:
                arr=[0]*8+arr
                arr[i]=1
        i-=1
         # num//=2
        num>>=1
    return arr

def toDecimal(arr):
    num=0
    j=0
    for i in range(len(arr)-1,-1,-1):
        if arr[i]:
            num+=(2**j)
        j+=1
    return num


if __name__=="__main__":
    arr=toBinary(2026)
    print(arr)
    num=toDecimal(arr)
    print(num)
