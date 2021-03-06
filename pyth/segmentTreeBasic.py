arr=[1,2,3,4,5,6,7,8,9]
map_arr=[-1]*len(arr) #maps arr elemt positions with segment_tree positions
segment_tree=[0]*(2*len(arr))
def build_tree(start,end,tree_start_index):
    if start==end:
        segment_tree[tree_start_index]=arr[start]
        map_arr[start]=tree_start_index
        return
    mid=(start+end)//2
    build_tree(start,mid,2*tree_start_index)
    build_tree(mid+1,end,2*tree_start_index+1)
    segment_tree[tree_start_index]=segment_tree[2*tree_start_index]+segment_tree[2*tree_start_index+1]
def update_tree(index,value):
    arr[index]=value
    segment_position=map_arr[index]
    old=segment_tree[segment_position]
    new=value
    segment_tree[segment_position]=value
    x=new-old
    if x==0:
        return
    segment_position=segment_position//2
    #----------------------------------------------------------------
    while segment_position>=1:
        segment_tree[segment_position]+=x
        segment_position=segment_position//2


if __name__=="__main__":
    build_tree(0,len(arr)-1,1)
    print("Before update")
    print(arr)
    print(segment_tree)
    print(map_arr)
    update_tree(2,13)
    print("After update")
    print(arr)
    print(segment_tree)
    print(map_arr)
