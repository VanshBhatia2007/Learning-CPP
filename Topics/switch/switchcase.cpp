#include<iostream>
using namespace std;
int main () {
    char ch;
    cin>>ch;
    switch(ch){
        case 'N':
        cout<<"north\n";
        break;
        case 'S':
        cout<<"south\n";
        break;
        case 'E':
        cout<<"east\n";
        break;
        default:
        cout<<"invalid";
    }
    
    return 0;
}