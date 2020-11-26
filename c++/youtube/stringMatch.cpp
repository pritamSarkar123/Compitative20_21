#include<iostream>
#include<string>
//Problem:-https://www.youtube.com/watch?v=tB2MoeWZx5M&t=768s
using namespace std;
int main(){
  long long int n;
  cout<<"Enter no of string want to Enter :"<<endl;
  cin>>n;
  string *names=new string[n];
  bool prince=false;
  for(long long int i=0;i<n;i++){
    cin>>names[i];
    if(names[i]=="prince"){
      prince=true;
    }
  }
  if(prince){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  delete[] names;
  return 0;
}
