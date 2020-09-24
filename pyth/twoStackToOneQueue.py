#Use two stacks for implementing one queue
import time
class Queue:
    def __init__(self):
        self.stack1=[]
        self.stack2=[]
    def enqueue(self,value):
        self.stack1.append(value)
    def dequeue(self):
        if not len(self.stack2):
            while len(self.stack1):
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()
    def showQueue(self):
        print(self.stack1)
        print(self.stack2)

if __name__=="__main__":
    t0=time.time()
    Q=Queue()
    for i in range(10):
        Q.enqueue(i)
    print(Q.dequeue())
    print(Q.dequeue())
    print(Q.dequeue())
    Q.showQueue()
    t1=time.time()
    print("Total time taken {}s".format(str((t1-t0)*1000000)))
