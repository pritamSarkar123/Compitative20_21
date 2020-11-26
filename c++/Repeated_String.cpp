//Problem:-https://www.hackerrank.com/challenges/repeated-string/problem
#include <iostream>
#include<string>
using namespace std;

long repeatedString(string s, long n) {
    long len=s.length();
    long repeat=n/len;
    long aCount=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a') aCount++;
    }
    aCount=aCount*repeat;
    long i=0;
    long end=n%len;
    while(i<end){
        if(s[i]=='a') aCount++;
        i++;
    }
    return aCount;
}

int main()
{
    string s;
    cin>>s;
    long n;
    cin>>n;
    cout<<repeatedString(s,n);
    return 0;
}
