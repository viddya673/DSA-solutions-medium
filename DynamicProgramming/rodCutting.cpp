#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int helper(int ind, int remaining, vector<int> price, vector<vector<int>>& dp){
	if(ind>price.size() || remaining==0)
		return 0;
	
	if(dp[ind-1][remaining]!=-1)
		return dp[ind-1][remaining];

	int take = INT_MIN;
	if(ind<=remaining){
		take = price[ind-1] + helper(ind, remaining-ind, price, dp);
	}

	int not_take = helper(ind+1, remaining, price, dp);

	return dp[ind-1][remaining] = max(take, not_take);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for(int len=1; len<=n; len++){
		for(int rem=0; rem<=n; rem++){
			int take = INT_MIN;
			if(len<=rem)
				take = price[len-1] + dp[len][rem-len];
			int not_take = dp[len-1][rem];
			dp[len][rem] = max(take, not_take);
		}
	}
	return dp[n][n];
	// return helper(1, n, price, dp);
}

int main(){
	vector<int> price{1, 5, 7, 6, 10};
	cout<<cutRod(price, 5);
}