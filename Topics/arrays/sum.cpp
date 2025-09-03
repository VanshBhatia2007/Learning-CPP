#include <iostream>
using namespace std;
int main(){
    int nums[]={1,5,11,7,2};
    int n=sizeof(nums)/sizeof(int);
    int target=9,sum;
    for(int i=0;i<n;i++){
        int a=i;
        for(int i=0;i<n;i++){
            sum=nums[i]+nums[a];
            if(sum==target){
                cout<<i<<","<<a;
                return 0;
            }
        }
    }
    return 0;
}