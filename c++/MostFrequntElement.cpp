//Problem:-https://www.geeksforgeeks.org/majority-element/
//finding most frequent element in an array using moore's algo
/*
    array=[8,8,6,4,6,6,6,3,6,6]
    res=0 count=1 leading=8
    i   count   leading     res
    1   2       8           0   
    2   1       8           0
    3   0       8           0
        1       4           3
    4   0       4           3
        1       6           4
    5   2       6           4
    6   3       6           4
    7   2       6           4
    8   3       6           4
    9   4       6           4
    
    ans=arr[res]=arr[4]=6

*/


#include <iostream>

using namespace std;

int main()
{
    int arr[]={8,8,6,4,6,6,6,3,6,6};   
    int count=1,res=0;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        if(arr[res]==arr[i]) count++;
        else count--;
        
        if(count==0){
            res=i;
            count=1;
        }
    }
    cout<<"The most frequent element is "<<arr[res]<<endl;
   return 0;
}
