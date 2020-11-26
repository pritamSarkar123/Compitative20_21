#include <iostream>
#include<vector>
using namespace std;
//https://www.youtube.com/watch?v=ENcnXXiRT6E&t=4s
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void reverse(vector<int> &arr,int low,int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;high--;
    }
}
int main()
{
   vector<int> arr{1,2,3,4,5,6,7}; 
   int k,j;
   cin>>k;
   k=k%arr.size();
   reverse(arr,0,arr.size()-k-1);
   reverse(arr,arr.size()-k,arr.size()-1);
   reverse(arr,0,arr.size()-1);
   for(int i=0;i<arr.size();i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   return 0;
}