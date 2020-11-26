#include<iostream>
using namespace std;

int fib(int arr[],int position){
    arr[0]=0;arr[1]=1;
    if(position<2){
        return position;
    }else{
        for(int i=2;i<=position;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[position];
    }
}

int main(){
    int position;
    cin>>position;
    int *arr=new int[position+1];
    cout<<fib(arr,position);
    delete[] arr;
    return 0;
}