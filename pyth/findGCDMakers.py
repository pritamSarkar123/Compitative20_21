#problem description
#https://www.youtube.com/watch?v=3kikC-LQ6dQ&t=17s
import math
M=[1,1,1,1,1,1,1,1,2,2,2,2,2,4,4,5,5,5,5,5,5,5,8,15,20]
A=[]
dic={}
def make():
	global M,A,dic
	count=-1
	while len(M):
		e=M.pop()
		A.append(e)
		count+=1
		i=0
		while i<=count:
			if (A[i],A[count]) not in dic.keys() or (A[count],A[i]) not in dic.keys():
				dic[(A[i],A[count])]=math.gcd(A[i],A[count])
				dic[(A[count],A[i])]=math.gcd(A[i],A[count])
			if dic[(A[i],A[count])] in M:
				M.remove(dic[(A[i],A[count])])
			i+=1
	
if __name__=="__main__":
	make()
	print(A)
