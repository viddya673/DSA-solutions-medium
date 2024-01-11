#include <climits>
#include <iostream>
#include <vector>
using namespace std;

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