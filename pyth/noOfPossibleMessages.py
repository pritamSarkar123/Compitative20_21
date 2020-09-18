#problem descripttion
#https://www.youtube.com/watch?v=qli-JCrSwuk&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev
table=[]
def helper(string,k):
    if k==0: #if string ="" or reached at end
        return 1
    s=len(string)-k
    if string[s]=="0":# if started with "0"
        return 0
    if table[k-1]==0:
        table[k-1]=helper(string,k-1)
    result=table[k-1]
    if k>=2 and int(string[s:s+2])<=26:
        if table[k-2]==0:
            table[k-2]=helper(string,k-2)
        result+=table[k-2]
    return result
def num_ways(string):
    return helper(string,len(string))
if __name__=="__main__":
    string="1234"
    for i in range(len(string)+1):
        table.append(0)
    print(num_ways(string)) 
