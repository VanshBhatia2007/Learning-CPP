#include <iostream>
using namespace std;

int main(){
    int n,i,j;
    bool p;
    cin>>n;

    for (i=2;i<=n;++i){
        p=true;
        for(j=2;j<i;++j){
            if(i%j==0){
                p = false;
            }
        }
        if(p){
            cout<<i<<"  ";
        }
        
    }
    return 0;
}