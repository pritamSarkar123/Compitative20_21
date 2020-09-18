#Segment tree
arr=[1,2,3,4,5,6,7,8,9]
segment_tree=[-1]*2*len(arr)
index_map=[-1]*len(arr)
MAX_INT=99999
def create_tree(start,end,tree_starting_index): #O(2*n-1)==O(n)
	global arr,segment_tree,index_map
	if start==end:
		segment_tree[tree_starting_index]=arr[start]
		index_map[start]=tree_starting_index
		return
	mid=(start+end)//2
	create_tree(start,mid,2*tree_starting_index)
	create_tree(mid+1,end,2*tree_starting_index+1)
	segment_tree[tree_starting_index]=min(segment_tree[2*tree_starting_index],segment_tree[2*tree_starting_index+1])
def update_tree(index,value): #O(log n)
	arr[index]=value
	s_index=index_map[index]
	segment_tree[s_index]=value
	s_index=s_index//2
	while s_index>=1:
		segment_tree[s_index]=min(segment_tree[2*s_index],segment_tree[2*s_index+1])
		s_index=s_index//2
def find_min(qstart,qend,start,end,tree_starting_index): #O(log n)
	#completely overlapped 
	if start>=qstart and end<=qend:
		return segment_tree[tree_starting_index] 
	#not overlapped atall
	elif start>qend or end<qstart:
		return MAX_INT
	#partially overlapped
	else:
		mid=(start+end)//2
		return min(find_min(qstart,qend,start,mid,2*tree_starting_index),find_min(qstart,qend,mid+1,end,2*tree_starting_index+1))

if __name__=="__main__":
	create_tree(0,len(arr)-1,1)
	print("Before")
	print(arr)
	print(segment_tree)
	print(index_map)
	update_tree(6,2)
	print("After")
	print(arr)
	print(segment_tree)
	print(index_map)
	print("min in range from {} to {} is {} ".format(3,8,find_min(3,8,0,8,1)))
	update_tree(6,7)
	print("After")
	print(arr)
	print(segment_tree)
	print(index_map)
	print("min in range from {} to {} is {} ".format(3,8,find_min(3,8,0,8,1)))
  

