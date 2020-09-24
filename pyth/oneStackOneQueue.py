#Use only one stack for implementing one Queue
#Time penalty
#Problem description:-https://www.youtube.com/watch?v=71kEvXsEKYQ
import time
class Queue:
    def __init__(self):
        self.stack1=[]
    def enqueue(self,value):
        self.stack1.append(value)
    def dequeue(self): #O(n) time
        if len(self.stack1)==1:
            return self.stack1.pop()
        else:
            poppedValue=self.stack1.pop()
            value=self.dequeue()
            self.stack1.append(poppedValue)
            return value
    def showQueue(self):
        print(self.stack1)

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
