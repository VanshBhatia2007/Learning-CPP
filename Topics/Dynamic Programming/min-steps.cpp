#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solve(int n){
    if(n==1) return 0;

    int op1=INT_MAX;
    int op2=INT_MAX;
    int op3=INT_MAX;

    if(n%3==0) op1=n/3;
    if (n % 2 == 0) {
		op2 = solve(n / 2);
	}

	op3 = solve(n - 1);

	return 1 + min(op1, min(op2, op3));
}

int topdown(int n,vector<int> &dp){
    // base case
	if (n == 1) return 0;

	if (dp[n] != -1) return dp[n];

	// recursive case
	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
	if (n % 3 == 0) op1 = topdown(n / 3, dp);
	if (n % 2 == 0) op2 = topdown(n / 2, dp);
	op3 = topdown(n - 1, dp);

	return dp[n] = 1 + min(op1, min(op2, op3));

}

int bottomdown(int n){
    vector<int> dp(n+1);
    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

        if(i % 3 == 0) op1 = dp[i / 3];
        if(i % 2 == 0) op2 = dp[i / 2];
        op3 = dp[i - 1];

        dp[i] = 1 + min(op1, min(op2, op3));
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"topdown: "<<topdown(n,dp)<<endl;
    cout<<"bottomdown: "<<bottomdown(n);
    return 0;

}
