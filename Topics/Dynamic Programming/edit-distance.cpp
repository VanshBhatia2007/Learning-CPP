#include<iostream>
#include<cstring>
using namespace std;

int topdown(string &s1,string &s2,int n,int m,int dp[][100]){
    //base case
    if(n==0) return m;
    if(m==0) return n;

    if(dp[n][m]!=-1) return dp[n][m];
    //recursive case
    if(s1[n-1]==s2[m-1]) return dp[n][m]=topdown(s1,s2,n-1,m-1,dp);

    else{
        int op1=topdown(s1,s2,n-1,m,dp); //insert
        int op2=topdown(s1,s2,n-1,m-1,dp);//update
        int op3=topdown(s1,s2,n,m-1,dp);//delete
        return dp[n][m]=1+min(op1,min(op2,op3));
    }
}

int main(){
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    string s1="saturday";
    string s2="sunday";
    cout<<topdown(s1,s2,s1.size(),s2.size(),dp);
    return 0;
}