#include <iostream>
using namespace std;

int main() {
    int a[20]={1};
    int n;
    n=sizeof(a)/sizeof(int);
    cout<<n<<endl;
    cout<<sizeof(a);
    return 0;
}