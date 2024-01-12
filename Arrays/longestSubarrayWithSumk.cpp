#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//using Hasing
int longestSubarrayWithSumK2(vector<int> a, long long k) {
    unordered_map<long long, int> mp;
    int maxLen = 0, currSum=0, n=a.size();

    for(int i=0; i<n; i++){
        currSum += a[i];
        if(currSum==k)
            maxLen = max(maxLen, i+1);
        int rem = currSum - k;
        if(mp.find(rem) != mp.end()){
            maxLen = max(maxLen, i-mp[rem]);
        }
        if(mp.find(currSum)==mp.end()){
            mp[currSum] = i;
        }

    }
    return maxLen;
}

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long currSum = 0;
    int n=a.size(), maxLen = INT_MIN, start=0;
    for (int i = 0; i < n; i++) {
        currSum += a[i];
        if(currSum==k){
            maxLen = max(maxLen, i-start+1);
        }else if(currSum > k){
            while(currSum>k){
                currSum -= a[start++];
            }
            if(currSum==k){
                maxLen = max(maxLen, i-start+1);
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int> a{8, 15, 17, 0, 11};
    cout<<longestSubarrayWithSumK(a, 17);
}