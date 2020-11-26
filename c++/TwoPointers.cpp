//problem:-https://www.youtube.com/watch?v=fpq-Sz_tpzM
#include <iostream>
#include<algorithm>
#include <cstdlib> 
using namespace std;
bool findSimilar(int index,int arr[],int n){
    int p=0;
    int q=n-1;
    int alter=-arr[index];
    int num;
    while(p<q){
        if(p==index) p++;
        else if(q==index) q--;
        else{
            num=arr[p]+arr[q];
            if(alter<num) q--;
            else if(alter>num) p++;
            else return true;
        }   
    }
    return false;
}
bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(findSimilar(i,arr,n)){
            return true;
        }
    }
    return false;
}
int main()
{
    //{9,21,64,50,82 ,31, 42 ,-33, 62, 24, 19, -30, 28, -2, 73, 23, 94, -45, 84, 7 ,1, 25, 20, 77, 9 ,-6 ,56, 2, 3, 3, 64 ,83, 28 ,-24, 59, -37, 55, 43, 77 ,-22 ,24};
    
    //{97 ,-27 ,2 ,-34 ,61,-39};
    int arr[]={9,21,64,50,82 ,31, 42 ,-33, 62, 24, 19, -30, 28, -2, 73, 23, 94, -45, 84, 7 ,1, 25, 20, 77, 9 ,-6 ,56, 2, 3, 3, 64 ,83, 28 ,-24, 59, -37, 55, 43, 77 ,-22 ,24};
    int n=sizeof(arr)/sizeof(int);
    cout<<findTriplets(arr,n)<<endl;
    return 0;
}

