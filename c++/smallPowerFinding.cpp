#include <iostream>
using namespace std;

int powerRecurssive(int a,int b);
int powerIterative(int a,int b);
int main()
{
   cout << powerIterative(2,8)<< endl; 
   cout << powerRecurssive(2,7) <<endl;
   return 0;
}
int powerIterative(int a,int b){
    int result=1;
    while(b>0){
        if(b & 1){
            result*=a;
            b--;
        }
        a*=a;
        b>>=1;
    }
    return result;
}
int powerRecurssive(int a,int b){
    if(b==0) return 1;
    else if(b & 1) return a*powerRecurssive(a*a,(b-1)/2);
    else return powerRecurssive(a*a,b/2);
}