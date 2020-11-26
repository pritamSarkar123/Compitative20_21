// Online C++ compiler to run C++ program online
#include<iostream>
#include<string>
using namespace std;
void printRevIter(string& str){
    int start=str.length()-1;
    int end;
    string rev="";
    while(start>=0){
        while(start>=0 && str[start]==' '){
            start--;
        }
        end=start;
        while(start>=0 && str[start]!=' '){
            start--;
        }
        rev+=" ";
        rev+=str.substr(start+1,end-start);
    }
    cout<<rev.substr(1)<<endl;
}
void printRevRec(int s,string& str){
    string word="";
    if(s>=str.length()){ //base condition
        return;
    }
    while(str[s]==' '){
        s++;
    }
    while(str[s]!=' ' && s<str.length()){
        word+=str[s];
        s++;
    }
    printRevRec(s,str);
    cout<<word<<" ";
}
int main() {
    string str="The sky is blue";
    printRevIter(str);
    printRevRec(0,str);
    return 0;
}