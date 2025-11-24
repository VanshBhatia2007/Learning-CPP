#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> a={1,2,3,4,5,6,7,9,10};
    cout<<*upper_bound(a.begin(),a.end(),6)<<endl;
    return 0;
}