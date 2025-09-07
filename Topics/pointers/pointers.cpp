#include <iostream>
using namespace std;

void update(int* &y){ //(int* &y)
    *y=*y+1;
    y=NULL;
}

int main(){
    int a=10;
    int *x=&a;
    update(x);
    cout<<a<<endl<<x;
    return 0;
}