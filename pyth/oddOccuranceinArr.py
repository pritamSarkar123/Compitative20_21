#problrm :-https://www.youtube.com/watch?v=bMF2fG9eY0A&t=23s
#O(n)

def usingHashMap():
	arr=[1,4,6,4,1]	
	d={}

	for i in arr:
		try:
		    d.pop(i)
		except:
		    d[i]=1

	print(list(d.keys())[0]),
	
def usingBitManipulation():
	arr=[1,4,6,4,1]
	xor=arr[0]
	for i in range(1,len(arr)):
		xor=xor^arr[i]
	print(xor)
	
usingHashMap()
usingBitManipulation()
