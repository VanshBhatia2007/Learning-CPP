#include <iostream>
using namespace std;

int main(){
    int a=10;
    int* b=&a;
    int c[]={10,2,03,10};
    int* d=c;
    cout<<&c<<endl;
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<*b;
    return 0;
}