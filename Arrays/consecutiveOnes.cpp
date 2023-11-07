#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int max_len = INT_MIN;
    int left = 0;
    int zero_count = 0;
    for(int right=0; right<n; right++){
        if(arr[right]==0){
            zero_count++;
        }

        while(zero_count>k){
            if(arr[left]==0){
                zero_count--;
            }
            left++;
        }

        max_len = max(max_len, right-left+1);
    }
    return max_len;
}

int main(){
    vector<int> arr{1, 0, 0, 1, 0, 1, 0, 1, 0};
    cout<<longestSubSeg(arr, arr.size(), 2);
}