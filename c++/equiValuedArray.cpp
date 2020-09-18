#include<iostream>
#include<vector>
#include<map>
using namespace std;
//problem description
//https://www.youtube.com/watch?v=qOHXdhtxyyQ&t=1245s
map<int,int> first,second;
int partition(){
    int n,v;
    long long sum=0,sdash=0;
    cout<<"Enter no of elements you want to include"<<endl;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        cin>>v;
        A.push_back(v);
    }
    for(int x:A){
        sum+=x;
    }
    if(sum & 1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"Initial array"<<endl;
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
    first[A[0]]=1;
    for(int i=1;i<n;i++) second[A[i]]++;
    for(int i=0;i<n;i++){
        sdash+=A[i];
        if(sdash==sum/2){
            cout<<"Yes"<<endl;
            return 1;
        }
        else if(sdash<sum/2){
            long long x=sum/2-sdash;
            if(second[x]>0){
                first[x]++;second[x]--;
                cout<<"Yes"<<endl;
                return 1;
            }
        }
        else{
            long long y=sdash-sum/2;
            if(first[y]>0){
                second[y]++;first[y]--;
                cout<<"Yes"<<endl;
                return 1;
            }
        }
        first[A[i+1]]++;second[A[i+1]]--;
    }
    cout<<"NO"<<endl;
    return 0;
}
int main(){
    int n=partition();
    if(!n) cout<<"Can not be pertitioned"<<endl;
    else{
        map<int,int>::iterator it;
        cout<<"First partition"<<endl;
        for(it=first.begin();it!=first.end();it++){
            if(it->second)
                cout<<"val "<<it->first<<" quantity "<<it->second<<endl;
        }
        cout<<"Second partition"<<endl;
        for(it=second.begin();it!=second.end();it++){
            if(it->second)
                cout<<"val "<<it->first<<" quantity "<<it->second<<endl;
        }
    }
    return 0;
}