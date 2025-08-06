#include <iostream>
using namespace std;
int main() {
    int n,i,r,a;
    cin >> n;
    r =1;
    while(r<=n){
        i=1;
        while(i<=n-r){
            cout << " ";
            i=i+1;
        }
        i = 1; 
        a = 1;
        while(i<=2*r-1){
            cout << a;
            a=a+1;
            i=i+1;
        }
        cout << "\n";
        r=r+1;
    }
    return 0;

}
