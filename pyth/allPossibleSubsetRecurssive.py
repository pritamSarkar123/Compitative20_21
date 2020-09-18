#problem description
#https://www.youtube.com/watch?v=bGC2fNALbNU&t=8s

a=[1,2,3,4]
b=[None]*len(a)

def helper(i):
	if i==len(b):
		print(b)
		return 
	b[i]=None
	helper(i+1)
	#b[i]=None<-----------redundent line not require atall
	b[i]=a[i]
	helper(i+1)
	b[i]=None
	
if __name__=="__main__":
	helper(0)

