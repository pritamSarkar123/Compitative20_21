#Problem Description:-
#https://www.youtube.com/watch?v=GBuHSRDGZBY
def findClosestPairSum(A,B,target):
    NEAREST_SMALLER_VAL=-9999;NEAREST_GREATER_VAL=9999
    i_min=0;j_min=0;i_max=0;j_max=0
    if len(A)!=len(B):
        return 
    A.sort();B.sort()
    i=len(A)-1;j=0
    while i>=0 and j<len(B):
        if A[i]+B[j]<target:
            if A[i]+B[j]>NEAREST_SMALLER_VAL:
                NEAREST_SMALLER_VAL=A[i]+B[j]
                i_min=i;j_min=j
            j+=1
        else:
            if A[i]+B[j]<NEAREST_GREATER_VAL:
                NEAREST_GREATER_VAL=A[i]+B[j]
                i_max=i;j_max=j
            i-=1
    print("Nerest sum making values :")
    print(f"Nearest smaller val : {NEAREST_SMALLER_VAL}")
    print(f"Given by A's {A[i_min]} and B's {B[j_min]}")
    print(f"Nearest greater val : {NEAREST_GREATER_VAL}")
    print(f"Given by A's {A[i_max]} and B's {B[j_max]}")
    
if __name__=="__main__":
    A=[-1,3,8,2,9,5]
    B=[4,1,2,10,5,20]
    target=24
    findClosestPairSum(A,B,target)
