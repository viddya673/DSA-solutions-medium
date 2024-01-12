#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

//using hashing
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(), count=0, currSum=0;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        currSum += arr[i];
        if(currSum==k)
            count++;
        int rem = currSum-k;
        if(mp.find(rem)!=mp.end()) count += mp[rem];
        mp[currSum]++;
    }
    return count;
}

int main(){
    vector<int> arr{3, 1, 2, 4, 6};
    cout<<findAllSubarraysWithGivenSum(arr, 6);
}