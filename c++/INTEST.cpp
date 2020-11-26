#include <iostream>
//Problem:-https://www.youtube.com/watch?v=MO0tef7aMPI&list=PLzjZaW71kMwTGbP1suqY16w1VSb9ZNuvE&index=6
//https://www.codechef.com/problems/INTEST
using namespace std;

int main()
{
    long long int n,k,sum=0,t;
    cin>>n;
    cin>>k;
    for(long long int i=0;i<n;i++){
        cin>>t;
        if(t%k==0){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
