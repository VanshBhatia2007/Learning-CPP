#include <iostream>
using namespace std;

void merge( int a[],int n,int b[],int m){
    int i=n-1, j=m-1,k=n+m-1;
    while(i>=0 and j>=0){
        if(a[i]>b[j]){
            a[k--]=a[i--];
        }
        else{
            a[k--]=b[j--];
        }
    }
    while(j>=0){
        a[k--]=b[j--];
    }

}

int print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
    int a[8]={3,5,7,8};
    int n=4;
    int b[4]={1,2,4,6};
    int m=sizeof(b)/sizeof(n);
    merge(a,n,b,m);
    print(a,n+m);
}