#Problem description
#https://www.youtube.com/watch?v=TUl1AsOfKP4&t=506s
outStack={'(':1,')':0}
inStack={'(':0,')':None}

givenString="(()((()()))((())))"
indexPositions=[-1]*len(givenString)
	

def find_value(low,high):
	global outStack,inStack,givenString,indexPosition
	if low+1==high:
		return 1
	match=indexPositions[low]
	if match==high:
		return 2*find_value(low+1,high-1)
	else:
		return find_value(low,match)+find_value(match+1,high)


if __name__=="__main__":
	recordStack=[]
	i=0
	recordStack.append([givenString[i],i])
	i+=1
	while len(recordStack):
		if outStack[givenString[i]]>inStack[recordStack[-1][0]]:
			recordStack.append([givenString[i],i])
		else:
			v=recordStack.pop()
			indexPositions[v[1]]=i
			indexPositions[i]=v[1]
		i+=1
	print(indexPositions)
	print(find_value(0,len(givenString)-1))
	
