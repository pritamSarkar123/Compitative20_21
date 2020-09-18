#problem description
#https://www.youtube.com/watch?v=5o-kdjv7FD0
def num_x_ways(n,x):
    if n==0:
        return 1
    nums=[0]*(n+1)
    nums[0]=1
    for i in range(1,n+1):
        total=0
        for j in x:
            if i-j>=0:
                total+=nums[i-j]
        nums[i]=total
    return nums[n]
if __name__=="__main__":
    print(num_x_ways(5,[1,2]))