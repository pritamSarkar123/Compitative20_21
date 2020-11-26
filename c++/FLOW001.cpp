#include <iostream>
//https://www.youtube.com/watch?v=1vUQsuAwpVw&list=PLzjZaW71kMwTGbP1suqY16w1VSb9ZNuvE&index=7
//https://www.codechef.com/problems/FLOW001
using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    int* arr=new int[t];
    for(int i=0;i<t;i++){
        cin>>a;
        cin>>b;
        arr[i]=a+b;
    }
    for(int i=0;i<t;i++){
        cout<<arr[i]<<endl;
    }
    delete[] arr;
    return 0;
}
