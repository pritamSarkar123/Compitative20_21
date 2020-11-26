//problem:-https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/?company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissions#
class solver
{
    public static void removeLoop(Node head){
        if(head==null) return;
        if(head.next==null) return;
        if(head.next.next==null) return;
        Node T= head;
        Node H=head.next.next;
        while(true){
            T=T.next;
            if(T==H) break;
            if(H.next==null) return;
            if(H.next.next==null) return;
            H=H.next.next;
        }
        int count=0;
        boolean begining=true;
        while(begining || T!=H){
            begining=false;
            T=T.next;
            count++;
        }
        count-=1;
        Node p=head,q=head;
        while(count!=0){
            p=p.next;
            count--;
        }
        while(p.next!=q){
            p=p.next;
            q=q.next;
        }
        p.next=null;
    }
}