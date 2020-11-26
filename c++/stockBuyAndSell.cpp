// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//problem description:
//https://www.youtube.com/watch?v=FsigpyvLPHA
void bruteForce(int arr[],int l){//O(n^2)
    int maxProfit=-9999;
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            if((arr[j]-arr[i])>maxProfit)
                maxProfit=arr[j]-arr[i];
        }
    }
    cout<<"Max profit "<<maxProfit<<endl;
}
void optimal(int arr[],int l){//O(n)
    int maxPrice=-9999;
    int minStock=9999;
    for(int i=0;i<l;i++){
        minStock=minStock>arr[i]?arr[i]:minStock;
        maxPrice=maxPrice<arr[i]-minStock?arr[i]-minStock:maxPrice;
    }
    cout<<"Max profit "<<maxPrice<<endl;
}
int main() {
    int arr[]={7,1,5,3,6,4};
    int len=sizeof(arr)/sizeof(int);
    bruteForce(arr,len);
    optimal(arr,len);
    return 0;
}
