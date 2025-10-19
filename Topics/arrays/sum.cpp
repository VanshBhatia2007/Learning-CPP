#include <iostream>
using namespace std;
int main(){
    int nums[]={1,0,2,4,5,3};
    int n=sizeof(nums)/sizeof(int);
    int target=5,sum;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum=nums[i]+nums[j];
            if(sum==target){
                cout<<nums[i]<<","<<nums[j]<<endl;
            }
        }
    }
    return 0;
}