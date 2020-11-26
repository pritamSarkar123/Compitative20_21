//Problem:-https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
//sulutions:-
/*
In merge process, let i is used for indexing left sub-array and j for right sub-array. 
At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
because left and right subarrays are sorted, so all the remaining elements in left-subarray 
(a[i+1], a[i+2] … a[mid]) will be greater than a[j]
*/
#include <iostream>
#include<vector>
using namespace std;
int *temp=NULL;

void merge(int a[],long l,long m,long h,long* count){
    long i=l,j=m+1,k=l;
    while(i<=m && j<=h){
        if(a[i]>a[j]){
            temp[k++]=a[j++];
            *count=*count+(m-i+1);
        }else{
            temp[k++]=a[i++];
        }
    }
    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=h){
        temp[k++]=a[j++];
    }
    i=l;
    for(k=l;k<=h;k++){
        a[i++]=temp[k];
    }
}


void mergeSort(int a[],long l,long h,long *count){
    if(h<=l) return;
    long mid=(l+h)/2;
    mergeSort(a,l,mid,count);
    mergeSort(a,mid+1,h,count);
    merge(a,l,mid,h,count);
}

long countInversions(vector<int> arr){
    long n=(long)arr.size();
    long count=0;
    int *a=new int[n];
    temp=new int[n];
    auto it=arr.begin();
    
    for(long i=0;i<arr.size();i++){
        a[i]=*it;
        it++;
    }
    
    mergeSort(a,0,n-1,&count);
    
    delete[] temp;
    delete[] a;
    return count;
}

int main()
{
    int b[]={2,1,3,1,2};
    vector<int> arr;
    for(int i=0;i<sizeof(b)/sizeof(int);i++){
        arr.push_back(b[i]);
    }
    cout<<countInversions(arr)<<endl;
    return 0;
}

