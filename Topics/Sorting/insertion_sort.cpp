#include<iostream>
using namespace std;

int main(){
    int a[]={2,1,3,4,5},j;
    int n=sizeof(a)/sizeof(int);

    for(int i=1;i<n;i++){
        int j ;
        int hpc=a[i];
        for(j=i-1;j>=0 && hpc<a[j];--j){
            a[j+1]=a[j];
        }
        a[j+1]=hpc;
    }
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    return 0;
}