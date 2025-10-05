#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);

    for(int i=0;i<=5;i++){
        v.push_back(i);
    }

    for(int i=0;i<=5;i++){
        cout<<v[i]<<" ";
        cout<<v.size()<<" ";
        cout<<v.capacity()<<" "<<endl;

    }
    cout<<endl;
    return 0;

}