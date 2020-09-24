#Problem description
#https://www.youtube.com/watch?v=RVIh0snn4Qc
## carefuly understand the brute force approach
def findMaxRectangle(I):
    MAX_SIZE=-9999
    bins=len(I)
    positions=[]
    heights=[]
    positions.append(0)
    heights.append(I[0])
    p=1
    while p<bins:
        if I[p]<=heights[-1]:
            _p=p
            while I[p]<=heights[-1]:
                heights.pop()
                _p=positions.pop()
                _h=I[p]*(p-_p+1) #h'=h*(p-p'+1)
                if _h>MAX_SIZE:
                    MAX_SIZE=_h
            heights.append(I[p])
            positions.append(_p)
        else:
            heights.append(I[p])
            positions.append(p)
        p+=1

    while len(heights):
        h=heights.pop()
        _p=positions.pop()
        _h=h*(bins-_p) #h*(bins-1-_p+1)
        if _h>MAX_SIZE:
            MAX_SIZE=_h
    return MAX_SIZE

if __name__=="__main__":
    I=[1,2,3,4,5,3,3,2]
    print(findMaxRectangle(I))
