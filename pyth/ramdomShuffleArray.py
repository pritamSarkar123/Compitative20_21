#Problem description
#https://www.youtube.com/watch?v=CoI4S7z1E1Y
import random
a=[1,0,3,9,2]
def randomSwap():
    global a
    for i in range(len(a)-1,0,-1):
        p=random.randint(0,i)
        a[i],a[p]=a[p],a[i]
    print(a)

if __name__=="__main__":
    randomSwap()
