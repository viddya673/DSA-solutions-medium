#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* Memoization */
int helper(int ind, int prev_ind, vector<int> rack, vector<vector<int>>& dp) {
	if (ind == rack.size())
		return 0;
	
	if(dp[ind][prev_ind+1] != -1)
		return dp[ind][prev_ind+1];

	int take = INT_MIN;
	if(prev_ind==-1 || rack[prev_ind]<rack[ind])
		take = rack[ind] + helper(ind+1, ind, rack, dp);

	int not_take = helper(ind+1, prev_ind, rack, dp);

	return dp[ind][prev_ind+1] = max(take, not_take);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	// return helper(0, -1, rack, dp);

    /* Tabulation */
	for(int i=n-1; i>=0; i--){
		for(int p=i-1; p>=-1; p--){
			int take = INT_MIN;
			if(p==-1 || rack[p]<rack[i])
				take = rack[i] + dp[i+1][i+1];
			int not_take = dp[i+1][p+1];
			dp[i][p+1] = max(take, not_take);
		}
	}
	return dp[0][0];
}

int main(){
    vector<int> rack = {5, 1, 2, 8};
    cout<<maxIncreasingDumbbellsSum(rack, rack.size());
}