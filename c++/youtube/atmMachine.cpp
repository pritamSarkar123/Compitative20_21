#include<iostream>
using namespace std;
// Problem:-https://www.youtube.com/watch?v=Au-Ntw3CYj0&t=3s
int main(){
  unsigned int amount;
  double balance;
  double remaining;
  cin>>amount;
  cin>>balance;
  if(amount%5==0){
    remaining=balance-amount-0.5;
    if(remaining>=0){
      cout<<remaining<<endl;
    }
    else{
      cout<<balance<<endl;
    }
  }else{
    cout<<balance<<endl;
  }
  return 0;
}
