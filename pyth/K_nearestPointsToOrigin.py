#problem descrption
#https://www.youtube.com/watch?v=eaYX0Ee0Kcg&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev&index=5
import math
import heapq
points=[
    [-2,4],[-1,0],[-2,-3],[3,2],[3,5],[0,-2]
]
distance=[]
k=3
for point in points:
    distance.append([math.sqrt(point[0]**2 + point[1]**2),point[0],point[1]])
print(distance)
heapq.heapify(distance)# based on 0th element #min heap
for i in range(k):
    v=heapq.heappop(distance)
    print(f"({v[1]},{v[2]})")