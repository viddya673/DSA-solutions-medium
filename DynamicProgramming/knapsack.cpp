#include <iostream>
#include <vector>
using namespace std;

// Recursion to memoization code
int knapsack(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>>& dp){
	if(n==0 || w==0)
		return 0;
	
	if(dp[n][w] != -1) return dp[n][w];

	int taken = 0, not_taken = 0;
	if(weights[n-1]<=w)
		taken = values[n-1]+knapsack(values,weights,n-1,w-weights[n-1], dp);
	
	not_taken = knapsack(values, weights, n-1, w, dp);

	return dp[n][w] = max(taken, not_taken);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
	return knapsack(values, weights, n, w, dp);
}

int main(){
    int max_weight = 10;
    vector<int> weights = {1, 3, 4, 6};
    vector<int> values = {20, 30, 10, 50};
    cout<<maxProfit(values, weights, 4, max_weight);
}