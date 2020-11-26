//Problem:-https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#
//Problem:-https://www.youtube.com/watch?v=FdObb76AmzM&t=24s

//Time:- O(n log(k))
//Space:-O(k)
class Solution
{
    public static ArrayList<Integer> kLargest(int arr[], int n, int k)
    {
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<n;i++){
            if(i<k){
                pq.add(arr[i]);
            }else{
                if(pq.peek()<arr[i]){
                    pq.remove();
                    pq.add(arr[i]);
                }
            }
        }
        // int[] ansArr=new int[k];
        // for(int i=k-1;i>=0;i--){
        //     ansArr[i]=pq.remove();
        // }
        // for(int i=0;i<k;i++){
        //     System.out.print(ansArr[i]+" ");
        // }
        // System.out.println();
        
        ArrayList<Integer> al=new ArrayList<>(pq);
        Collections.sort(al,Collections.reverseOrder());
        return al;
    }
}