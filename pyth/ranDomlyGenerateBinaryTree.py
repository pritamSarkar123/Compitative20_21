class Node:
    def __init__(self,value=0,left=None,right=None):
        self.value=value
        self.left=left
        self.right=right
class BinaryTree:
    def __init__(self):
        self.head=None
        self.Q=[]
    def createTree(self):
        inp=int(input("Enter the head Node "))
        if inp==-1:
            print("No head created")
            return
        else:
            self.head=Node(inp)
            self.Q.append(self.head)
            while len(self.Q):
                temp=self.Q.pop(0)
                inp=int(input("Enter left child of "+str(temp.value)+" : "))
                if(inp!=-1):
                    temp.left=Node(inp)
                    self.Q.append(temp.left)
                inp=int(input("Enter right child of "+str(temp.value)+" : "))
                if(inp!=-1):
                    temp.right=Node(inp)
                    self.Q.append(temp.right)
    def printTree(self,temp):
        if temp==None:
            return
        print(temp.value)
        self.printTree(temp.left)
        self.printTree(temp.right)

    def showTree(self):
        self.printTree(self.head)

if __name__=="__main__":
    b=BinaryTree();
    b.createTree();
    b.showTree()
