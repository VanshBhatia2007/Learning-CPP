#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> v;
    v.push_back({1,2,3});
    v.push_back({4,5,6,7,8,9,10});

    for(int i=0;i<v[1].size();i++){
        cout<<v[1][i]<<" ";

    } 
    cout<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<endl;
    return 0;

}