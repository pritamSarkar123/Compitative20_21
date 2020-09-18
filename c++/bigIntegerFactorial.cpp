#include<iostream>
//problem description:https://www.youtube.com/watch?v=2fYZERB2Yng
using namespace std;
void factorial(int num){
    int a[1000000]={1};
    int value,carry,length=1,i;
    while(num>=2){
        i=0;carry=0;
        while(i<length){
            value=a[i]*num;
            a[i++]=(value%10)+carry;
            carry=value/10;
        }
        while(carry){
            a[i++]=carry%10;
            carry=carry/10;
            length++;
        }
        num--;
    }
    length--;
    cout<<"Result: "<<endl;
    while(length>-1){
        cout<<a[length--];
    }
    cout<<endl;
}

int main(int argc, char **argv){
    cout<<"Enter the number"<<endl;
    int num;
    cin >> num;
    factorial(num);
    return 0;
}