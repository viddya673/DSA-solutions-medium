#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private: 
void helper(int i, int k, vector<int> candidates, vector<int> temp, vector<vector<int>>& res)   {
        if(k==0){
            res.push_back(temp);
            return;
        }

        for(int j=i; j<candidates.size(); j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>k) break;

            temp.push_back(candidates[j]);
            helper(j+1, k-candidates[j], candidates, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, temp, res);
        return res;
    }
};

int main(){
    vector<int> temp;
    vector<int> nums {2,3,6,7};
    int n = nums.size();

    Solution s;
    vector<vector<int>> res = s.combinationSum2(nums, 7);
    for(auto it: res){
        for(int i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}