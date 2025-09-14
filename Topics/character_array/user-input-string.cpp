#include <iostream>
using namespace std;

void print(char a[],int n,char ch){
    int i=0;
    while(i <n-1 and ch!='\n'){
        a[i]=ch;
        i++;
        ch=cin.get();
    }
    a[i] = '\0';
    cout<<a<<endl;
}

int main(){
    char a[100];
    char ch;
    ch=cin.get();
    print(a,5,ch);
    
    return 0;
}