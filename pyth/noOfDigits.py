#finding no of digits in a number in O(1) time
import math
num=int(input("Enter the number "))
if num<0:
    num*=(-1)
print(int(math.log10(num))+1)
