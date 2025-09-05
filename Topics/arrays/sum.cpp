#include <iostream>
using namespace std;
int main(){
    int nums[]={1,0,2,4,5,3};
    int n=sizeof(nums)/sizeof(int);
    int target=5,sum;
    for(int i=0;i<n;i++){
        int a=i;
        for(int i=0;i<n;i++){
            sum=nums[i]+nums[a];
            if(sum==target){
                cout<<nums[a]<<","<<nums[i]<<endl;
            }
        }
    }
    return 0;
}