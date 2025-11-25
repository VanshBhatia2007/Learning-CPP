#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int lcs(string &s1, string &s2,int n,int m,int dp[][100]){
	if(n==0 or m==0) return 0;

	if(s1[n-1]==s2[m-1]) return 1+lcs(s1,s2,n-1,m-1,dp);

	else{
		return max(lcs(s1,s2,n-1,m,dp),
		lcs(s1,s2,n,m-1,dp));
	}
}

int topdown(string s1, string s2, int n, int m, int dp[][100]) {
	if (n == 0 || m == 0) {
		return dp[n][m] = 0;
	}

	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	if (s1[n - 1] == s2[m - 1]) {
		return dp[n][m] = 1 + topdown(s1, s2, n - 1, m - 1, dp);
	}
	else {
		int op1 = topdown(s1, s2, n, m - 1, dp);
		int op2 = topdown(s1, s2, n - 1, m, dp);
		return dp[n][m] = max(op1, op2);
	}
} 

int bottomup(string s1, string s2) {
	int dp[100][100] = {};

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[s1.size()][s2.size()];
}


int main() {

	string s1 = "abcde";
	string s2 = "acbde";
	int dp[100][100];
	memset(dp, -1, sizeof(dp));

	cout << topdown(s1, s2, s1.size(), s2.size(), dp) << endl;
	cout << bottomup(s1, s2) << endl;
	cout << lcs(s1, s2, s1.size(), s2.size(),dp) << endl;

	return 0;
}