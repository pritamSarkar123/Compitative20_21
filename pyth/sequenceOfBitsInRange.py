'''
give N
r=[]
for i =0 to N:
    r.append(noOfBits(i))

eg:
5
[0,1,1,2,1,2]
'''

'''
O(N^2)
external loop: N
    count(..) N
'''
def approach1(N):
    r=[]
    for i in range(N+1):
        r.append(bin(i)[2:].count("1"))
    return r

'''
O(N log N)
external loop: N
    count_: log N
'''
def approach2(N):
    r=[]
    def count_(x):
        c=0
        while x:
            c+=1
            x=x & (x-1)
        return c
    for i in range(N+1):
        r.append(count_(i))
    return r
'''
dynamic programming
      0
    /  \
   1    2
  / \  / \
 3   4,5   6
     000
   /     \
  001    010
 / \    /   \
011 100,101 110

no of ones in child node =no of ones in parent node +(child node index%2)

takes O(N) time
external loop: N
    internal: 1
'''
def approach3(N):
    r=[]
    r.append(0)
    for i in range(1,N+1):
        r.append(r[i//2]+(i%2))
    return r




N=6
print(approach1(N))
print(approach2(N))
print(approach3(N))
