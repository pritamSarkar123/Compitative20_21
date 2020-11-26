#include <iostream>
//Problem:- https://www.youtube.com/watch?v=-YiQZi3mLq0
// comment section
/*
    
    hey i have an alternate solution for finding head.
after hare and tortoise meet. we will make hare pointer stop at that point and make tortoise pointer move till it reaches hare pointer again and count number on nodes.
this will give us length of cycle. ( how many nodes are in cycle). lets denote dis with c.
then just take 2 pointers p1 and p2 at c distance apart.. and move both at SAME speed till p1 and p2 meets. that point will be head.
    

*/


using namespace std;
class Node{
        public:
        int value;
        Node *next=NULL;
        Node(int v){
            value=v;
        }
    };

class LinkedList{
    public:
    Node* head=NULL;
    int length;
    LinkedList(){
        length=0;
        cout<<"List created"<<endl;
    };
    void add(int a){
        Node *n=new Node(a);
        n->next=head;
        head=n;
    }
    void createCircularList(int len,int at){
        length=len;
        for(int i=0;i<len;i++){
            add(i+1);
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        if(at==-1) return;
        Node* p=head;
        while(at){
            p=p->next;
            at--;
        }
        temp->next=p;
    }
    bool isCircular(){
        if(!head) return false;
        if(!head->next) return false;
        Node *H=head,*T=head;
        bool initial=true;
        while(initial || H!=T){
            initial=false;
            if(!H) return false;
            if(H->next){
                H=(H->next)->next;
            }if(T->next){
                T=T->next;
            }
        }
        return true;
    }
    Node* circleHead(){
        if(!isCircular()) return NULL;
        Node *H=head,*T=head;
        bool initial=true;
        while(initial || H!=T){
            initial=false;
            H=(H->next)->next;
            T=T->next;
        }
        //Step 1
        initial=true;
        int count=0;
        while(initial || H!=T){
            initial=false;
            count++;
            T=T->next;
        }
        //Step 2
        Node* p1=head,*p2=head;
        while(count>=1){
            p2=p2->next;
            count--;
        }
        //Step 3
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
    ~LinkedList(){
        Node* n=head;
        for(int i=0;i<length;i++){
            delete n;
            n=n->next;
        }
        cout<<"Cleared"<<endl;
    }
};

int main()
{
   LinkedList l;
   l.createCircularList(7,3);
   cout<<l.isCircular()<<endl;
   Node* circleHead=l.circleHead();
   if(circleHead) cout<<circleHead->value<<endl;
   else cout<<"No circular head"<<endl;
   return 0;
}