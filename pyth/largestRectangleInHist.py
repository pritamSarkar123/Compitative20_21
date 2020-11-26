#Problem description
#https://www.youtube.com/watch?v=RVIh0snn4Qc
## carefuly understand the brute force approach
def findMaxRectangle(I):
    bins=len(I)
    if bins==0:
        return 0
    if bins==1:
        return I[0]
    P=[]
    H=[]
    P.append(0)
    H.append(I[0])
    MAX_SIZE=-9999
    pointer=1
    while pointer<bins:
        while len(H) and H[-1]>I[pointer]:
            p_ = P.pop()
            h_ = H.pop()
            size = h_ * (pointer - p_)
            if size>MAX_SIZE:
                MAX_SIZE=size
        # if H[-1]<=I[pointer]
        P.append(pointer)
        H.append(I[pointer])
        pointer+=1
    while len(H): # when pointer > bins:
        p_ = P.pop()
        h_ = H.pop()
        size = h_ * (bins - p_)
        if size>MAX_SIZE:
            MAX_SIZE=size
    return MAX_SIZE


if __name__=="__main__":
    #I=[1,2,0,4,5,0,3,2]
    I=[1,2,3,4,5,3,3,2]
    zeroes=[]
    for i in range(len(I)):
        if not I[i]:
            zeroes.append(i)
    finalMax=-9999
    nonzero=0
    for zero in zeroes:
        m=findMaxRectangle(I[nonzero:zero])
        nonzero=zero+1
        if m>finalMax:
            finalMax=m
    m=findMaxRectangle(I[nonzero:])
    if m>finalMax:
        finalMax=m
    print(finalMax)
