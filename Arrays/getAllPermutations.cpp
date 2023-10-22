#include <iostream>
#include <vector>
using namespace std;

void getAllPermutations(int idx, vector<vector<int>>& result, vector<int> nums){
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        swap(nums[i], nums[idx]);
        getAllPermutations(idx+1, result, nums);
    }
}

int main(){
    vector<int> v{1,2,3};
    vector<vector<int>> res;
    getAllPermutations(0, res, v);
    for(auto r: res){
        for(int i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}