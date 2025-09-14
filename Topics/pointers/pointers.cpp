#include <iostream>
using namespace std;

void update(int *y){ //(int* &y)
    *y=*y+1;
}

int main(){
    int a=10;
    int *x=&a;
    update(x);
    cout<<a;
    return 0;
}