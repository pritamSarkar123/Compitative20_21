#problem description
#https://www.youtube.com/watch?v=71kEvXsEKYQ
stack=[1,2,3,4,5]
def dequeue():
    global stack
    if not len(stack):
        return None
    elif len(stack)==1:
        return stack.pop()
    else:
        popped_value=stack.pop()
        value=dequeue()
        stack.append(popped_value)
        return value

if __name__=="__main__":
    print(dequeue())
    print(dequeue())
    print(dequeue())
