#include <iostream>
using namespace std;
//problem:-https://www.codechef.com/problems/FLOW006
int sum(long long int N){
    int sum=0;
    while(N){
        sum+=N%10;
        N/=10;
    }
    return sum;
}
int main()
{
    int T;
    long long int N;
    cin>>T;
    int *arr=new int[T];
    for(int i=0;i<T;i++){
        cin>>N;
        arr[i]=sum(N);
    }
    for(int i=0;i<T;i++){
        cout<<arr[i]<<endl;
    }
    delete[] arr;
    return 0;
}
