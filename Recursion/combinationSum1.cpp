#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(int n, int k, vector<int> nums, vector<int>& temp, vector<vector<int>>& res){
        if(n<0){
            if(k==0)
                res.push_back(temp);
            return;
        }

        //take
        if(k>=nums[n]){
            temp.push_back(nums[n]);
            helper(n, k-nums[n], nums, temp, res);
            temp.pop_back();
        }

        //not take
        helper(n-1, k, nums, temp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        int n = candidates.size();
        helper(n-1, target, candidates, temp, res);
        return res;
    }
};

int main(){
    vector<int> temp;
    vector<int> nums {2,3,6,7};
    int n = nums.size();

    Solution s;
    vector<vector<int>> res = s.combinationSum(nums, 7);
    for(auto it: res){
        for(int i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}