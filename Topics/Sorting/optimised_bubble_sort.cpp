#include<iostream>
using namespace std;
int main () {
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(int);

    for(int i=0;i<n-1;++i){
        bool swaphua=false;
        for(int j=0;j<n-1;++j){
            if(a[j]>a[j+1]){
                swaphua=true;
                swap(a[j],a[j+1]);
            }
        
        }
    if(swaphua==false){
        break;
    }
    
    }
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }

    
    return 0;
}