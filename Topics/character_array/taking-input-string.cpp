#include <iostream>
using namespace std;

int main(){
    char a[100];
    cin.getline(a,100); //default delimiter ='\n'
    cout<<a<<endl;
    for(int i=0;a[i] !='\0';++i){
        cout<<a[i]<<endl;
        
    }
    return 0;
}