/* Print all subsets without repetition */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void helper(int ind, vector<int> nums, vector<int> temp, vector<vector<int>>& res){
        res.push_back(temp);

        for(int k=ind; k<nums.size(); k++){
            if(k>ind && nums[k]==nums[k-1]) continue;

            temp.push_back(nums[k]);
            helper(k+1, nums, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(0, nums, temp, res);
        return res;
    }
};

int main(){
    vector<int> nums {1, 2, 2};
    Solution s;

    vector<vector<int>> res = s.subsetsWithDup(nums);
    for(auto item: res){
        for(int i: item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}