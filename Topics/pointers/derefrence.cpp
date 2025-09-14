#include <iostream>
using namespace std;


int main(){
    int a=1;
    cout<<&a<<endl;
    cout<<*(&a)<<endl;
    return 0;
}
/* x=10
&x=100
y=100
&y=200
*(&x)=10
&(*y)=100
x+1=11
&x+1=104
y+1=104
*y+1=11
*(&y)=100
*/
