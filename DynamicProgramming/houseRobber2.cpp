#include <bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

long long int solve(int n, vector<int>& valueInHouse){
    vector<long long> dp(n, -1);
    dp[0] = valueInHouse[0];

    for(int i=1; i<n; i++){
        long long int rob = valueInHouse[i];
        if(i>1)
            rob += dp[i-2];
        long long int dont_rob = dp[i-1];
        dp[i] = max(rob, dont_rob);
    }
    return dp[n-1];
} 
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1)
        return valueInHouse[0];

    vector<int> arr1;
    vector<int> arr2;

    for(int i=0; i<n; i++){
        if(i!=0) arr1.push_back(valueInHouse[i]);
        if(i!=n-1) arr2.push_back(valueInHouse[i]);
    }
    
    long long int ans1 = solve(n-1, arr1);
    long long int ans2 = solve(n-1, arr2);

    return max(ans1, ans2);
}

int main()
{
    vector<int> houses{1,5,1,2,6};
    cout<<houseRobber(houses);
}