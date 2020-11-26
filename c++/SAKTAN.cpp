#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
#define ll long long 
using namespace std;
ll int t,n,m,q,x,y;
ll int odds,evens,total_odds;
int main(){
    cin>>t;
    while(t--){
        odds=0;evens=0;total_odds=0;
        cin>>n>>m>>q;
        ll int r[n+1];memset(r,0,sizeof(r));
        ll int c[m+1];memset(c,0,sizeof(c));
        for(ll int j=0;j<q;j++){
            cin>>x>>y;
            r[x]++;c[y]++;
        }
        for(ll int j=1;j<n+1;j++){
            if(r[j]%2==0) evens++;
            else odds++;
        }
        for(ll int j=1;j<m+1;j++){
            if(c[j]%2!=0) total_odds+=evens;
            else total_odds+=odds;
        }
        cout<<total_odds<<endl;
    }
    return 0;
}