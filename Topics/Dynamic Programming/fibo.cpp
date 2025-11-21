#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int fibo(int n) {// T.C -> 2^N
	if (n <= 1) {
		return n;
	}

	return fibo(n - 1) + fibo(n - 2);
}

int topdown(int n,vector<int> &dp){ //O(N)
    //base case
    if(n<=1) return n;

    if(dp[n]!=-1){
        return dp[n];
    }
    //recursive case
    dp[n]=topdown(n-1,dp)+topdown(n-2,dp);
    return dp[n];
}

int bottomup(int n,vector<int> &dp){
    vector<int> dp(n+1);
    dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}




int main(){
    int n;
	cin >> n;
	// int dp[10000];
	// for (int i = 0; i <= n; ++i)
	// {
	// 	dp[i] = -1;
	// }
    //memset(dp,-1,sizeof dp) //for array we can use this inbuilt function
    vector<int> dp(n+1,-1);
	cout <<"topdown :" <<topdown(n, dp) << endl;
	cout << "bottomup :"<<bottomup(n,dp) << endl;
	// cout << fibo(n) << endl;

    return 0;
}
