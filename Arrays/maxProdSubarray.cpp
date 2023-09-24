#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1, maxi = nums[0];

        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            int temp_max = max(prefix, suffix);
            maxi = max(temp_max, maxi);
            if(prefix==0)
                prefix = 1;
            if(suffix==0)
                suffix = 1;
        }
        return maxi;
    }
};

int main(){
    vector<int> nums{2,3,-2,4};
    Solution s;
    cout<<s.maxProduct(nums);
}