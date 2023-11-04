#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
void helper(int ind, vector<int> nums, vector<vector<int>>& arr){
    if(ind==nums.size()){
        arr.push_back(nums);
        return;
    }

    for(int k=ind; k<nums.size(); k++){
        swap(nums[ind], nums[k]);
        helper(ind+1, nums, arr);
        swap(nums[ind], nums[k]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = s.permute(nums);
    for(auto r: res){
        for(int i: r)
            cout<<i<<" ";
        cout<<endl;
    }
}