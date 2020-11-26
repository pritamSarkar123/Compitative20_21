#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Problem:-https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/
void rearrange(vector<long long int> &V){
    long long int min,max,maxTerm;
    min=0;max=V.size()-1;maxTerm=V[V.size()-1]+1;
    for(long long int i=0;i<V.size();i++){ 
        if(i%2==0){ //max elemts at even positions
            V[i]=(V[max]%maxTerm)*maxTerm+V[i];
            max--;
        }else{ //min elemts at odd positions
            V[i]=(V[min]%maxTerm)*maxTerm+V[i];
            min++;
        }
    }
    for(long long int i=0;i<V.size();i++){
        V[i]/=maxTerm;
    }
}
int main() {
    vector<long long int> V;
    bool sorted;
    int T;
    cin>>T;
    long long int N,val;
    while(T--){
        cin>>N;
        for(long long int i=0;i<N;i++){
            cin>>val;
            V.push_back(val);
        }
        sorted=true;
        for(long long int i=0;i<V.size()-1;i++){ //O(N)
            if(V[i]>V[i+1]){
                sorted=false;
                break;
            }
        }
        if(!sorted) sort(V.begin(),V.end()); //O(Nlog(N))
        rearrange(V);
        for(long long int i=0;i<V.size();i++){
            cout<<V[i]<<" ";
        }
        cout<<endl;
        V.clear();
    }
	
	return 0;
}