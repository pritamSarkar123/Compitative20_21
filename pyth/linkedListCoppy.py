#problem description
#https://www.youtube.com/watch?v=xbpUHSKoALg&t=784s

# algorithm:
# 	#create intermediate nodes
# 	p=head
# 	q=NULL
# 	while p!=NULL:
# 		q=p
# 		p=p->next
# 		t=copy(q)
# 		q->next=t
# 		t->next=p
	
# 	#connecting new linked list
# 	p=head
# 	q=NULL
# 	while p!=NULL:
# 		q=p
# 		p=p->next->next
# 		q->next->random=q->random->next
# 		q=q->next
# 		if p!=NULL:
# 			q->next=p->next
# 		else:
# 			q->next=NULLa
# 	#changing head pointer
# 	head=head->next

class Node:
	def __init__(self,value):
		self.value=value
		self.next=None
		self.random=None
		self.message="Original"
class LinkedList:
	def __init__(self):
		self.head=Node(1)
		temp=self.head
		temp.next=Node(2)
		temp=temp.next
		temp.next=Node(3)
		temp=temp.next
		
		temp=self.head
		temp.random=temp.next.next #1->3
		
		temp=temp.next
		temp.random=self.head #2->1
		
		temp=temp.next
		temp.random=temp #3->3
	def show_list(self):
		temp=self.head
		while temp:
			print(temp.value,temp.message,temp.random.value)
			temp=temp.next
	def copy_list(self):
		#create intermediate nodes
		p=self.head
		q=None
		while p:
			q=p
			p=p.next
			temp=Node(q.value);temp.message="Coppied"
			q.next=temp
			temp.next=p
		#connecting new linked list
		p=self.head
		q=None
		while p:
			q=p
			p=p.next.next
			q.next.random=q.random.next
			q=q.next
			if p:
				q.next=p.next
			else:
	 			q.next=None
 		#changing head pointer
		self.head=self.head.next
		self.show_list()
			
if __name__=="__main__":
	myList=LinkedList()
	myList.show_list()
	myList.copy_list()
		
