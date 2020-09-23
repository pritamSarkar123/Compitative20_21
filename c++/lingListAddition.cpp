//https://www.youtube.com/watch?v=J1JZjhdr3Oo&t=53s
#include<iostream>
using namespace std;
class LinkedList;
class AddLinkedList;

class Node{
  int value;
  Node *next=NULL;
  friend LinkedList;
};


class LinkedList{
private:
  Node* head=NULL;
  Node* tail=NULL;
  int nodeCounter;
  int blankList;
public:
  friend AddLinkedList;
  LinkedList(int arr[],int len){
    blankList=0;
    nodeCounter=0;
    Node *newNode=NULL;
    int start=0;
    int i=0;
    while(arr[i]==0 && i<len) i++;
    start=i;
    if(start==len){
      cout<<"Impossible to create List"<<endl;
      blankList=1;
      return;
    }
    for(int i=start;i<len;i++){
      newNode=new Node;
      newNode->value=arr[i];
      if(i==start){
        tail=newNode;
        head=tail;
      }
      else{
        tail->next=newNode;
        tail=tail->next;
      }
      nodeCounter++;
    }
  }
  LinkedList(){
    nodeCounter=0;
  };
  int getTailValue();
  void createList(int n);
  void showList();
  ~LinkedList(){
    if(head==NULL) return;
    else{
      Node* temp=head;
      while(head){
        head=head->next;
        delete temp;
        temp=head;
      }
    }
  }
};
class AddLinkedList{
public:
  LinkedList l3;
  AddLinkedList(LinkedList &l1,LinkedList &l2){
    int carry=0;int x,y;
    if(l1.blankList||l2.blankList){
      if(l1.blankList){
        l3.head=l2.head;
        l3.tail=l2.tail;
        l3.nodeCounter=l2.nodeCounter;
        l3.blankList=l2.blankList;
        return;
      }
      else if(l2.blankList){
        l3.head=l1.head;
        l3.tail=l1.tail;
        l3.nodeCounter=l1.nodeCounter;
        l3.blankList=l1.blankList;
        return;
      }
    }
    while(l1.nodeCounter && l2.nodeCounter){
      x=l1.getTailValue();
      y=l2.getTailValue();
      l3.createList(((x+y)+carry)%10);
      carry=((x+y)+carry)/10;
    }
    if(l1.nodeCounter){
      x=l1.getTailValue();
      l3.createList((x+carry)%10);
      carry=(x+carry)/10;
    }
    else if(l2.nodeCounter){
      y=l2.getTailValue();
      l3.createList((y+carry)%10);
      carry=(y+carry)/10;
    }
    if(carry){
      l3.createList(carry%10);
      carry=carry/10;
    }
  }
};

int main(){
  int arr1[]={0,4,0,5};
  int arr2[]={0,5,8,3,1};
  LinkedList l1(arr1,sizeof(arr1)/sizeof(int)),l2(arr2,sizeof(arr2)/sizeof(int));
  cout<<"Array One"<<endl;
  l1.showList();
  cout<<"Array Two"<<endl;
  l2.showList();
  AddLinkedList ALL(l1,l2);
  cout<<"Output"<<endl;
  ALL.l3.showList();
  return 0;
}

int LinkedList::getTailValue(){
  int value;
  value=tail->value;
  nodeCounter--;
  int i=0;
  tail=head;
  while(i<nodeCounter-1){
    tail=tail->next;
    i++;
  }
  return value;
}
void LinkedList::createList(int n){
  Node *newNode=new Node;
  newNode->value=n;
  if(head==NULL){
    head=newNode;
    tail=head;
  }
  else{
    newNode->next=head;
    head=newNode;
  }
  nodeCounter++;
}
void LinkedList::showList(){
  Node* temp=head;
  while(temp){
    if(temp->next==NULL){
      cout<<temp->value;
    }
    else{
        cout<<temp->value<<"->";
    }
    temp=temp->next;
  }
  cout<<endl;
}
