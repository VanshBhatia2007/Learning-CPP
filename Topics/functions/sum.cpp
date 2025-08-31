#include<iostream>
using namespace std;
int add(int x,int y){ //parameters
    int ans= x+y;
    return ans;
}

int main () {
    int a=5 , b=10;
    int sum= add(a,b);
    cout<<"sum: "<<sum<<endl;
    
    return 0;
}