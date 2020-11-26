#include <iostream>
//https://www.youtube.com/watch?v=LPFhl65R7ww&feature=emb_logo
//complexity O(log(min(x,y))
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

double findMaidan(const vector<int> &a,const vector<int> &b){
    if(a.size()>b.size()){
        return findMaidan(b,a);
    }
    int x=a.size();int y=b.size();
    int begin=0;
    int end=x;
    while(begin<=end){
        int partitionX=(begin+end)/2;
        int partitionY=(x+y+1)/2 - partitionX;
        int maxLeftX=(partitionX==0)?INT_MIN:a[partitionX-1];
        int maxLeftY=(partitionY==0)?INT_MIN:b[partitionY-1];
        int minRightX=(partitionX==x)?INT_MAX:a[partitionX];
        int minRightY=(partitionY==x)?INT_MAX:b[partitionY];
        //at junction left set all smaller right set al greater elements
        if((maxLeftY<=minRightX)&&(maxLeftX<=minRightY)){
            if((x+y)%2==0){
                return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2;
            }else{
                return (double)(max(maxLeftX,maxLeftY));
            }
        }else if(maxLeftY>minRightX){//we are too far in left we have to move right in a
            begin=partitionX+1;
        }else{//we are too far in right we have to move left in a
            end=partitionX-1;
        }
    }
}
int main()
{
   vector<int> a{10,20,30};
   vector<int> b{5,15,25,35,45};
   double median=findMaidan(a,b);
   cout<<median<<endl;
   return 0;
}