#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1; i>idx; i--){
            if(nums[idx]<nums[i]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
};

int main(){
    vector<int> nums{1,2,3};
    Solution s;
    s.nextPermutation(nums);
    for(int n: nums)
        cout<<n<<endl;
}