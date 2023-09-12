#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> targetSumSubarray(vector<int> arr, int sum) {
    int n = arr.size();
    vector<int> res;
    map<int, int> mp;
    int curr_sum=0;
    int start = 0;
    int end = -1;

    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum-sum==0){
            end = i;
            break;
        }
        if(mp.find(curr_sum-sum)!=mp.end()){
            start = mp[curr_sum-sum]+1;
            end = i;
            break;
        }
        mp[curr_sum] = i;
    }

    if(end!=-1){
        res = {start, end};
    }
    return res;
}

int main() {
    vector<int> arr = {10, 15, -15, 15, -10, 5};
    int sum = 5;

    vector<int> res = targetSumSubarray(arr, sum);
    
    if (res.empty()) {
        cout << "No subarray found with the target sum." << endl;
    } else {
        for(int x: res)
            cout<<x<<endl;
    }
    return 0;
}