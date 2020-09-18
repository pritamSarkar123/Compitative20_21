#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,v;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        cin>>v;
        A.push_back(v);
    }
    cout<<"------------"<<endl;
    for(int x:A){
        cout<<x<<endl;
    }
    return 0;
}