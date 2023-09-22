#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        // vector<int> left_prod(n);
        // vector<int> right_prod(n);

        // left_prod[0] = 1;
        // for(int i=1; i<n; i++)
        //     left_prod[i] = left_prod[i-1] * nums[i-1];

        // right_prod[n-1] = 1;
        // for(int i=n-2; i>=0; i--)
        //     right_prod[i] = right_prod[i+1] * nums[i+1];

        // for(int i=0; i<n; i++)
        //     ans[i] = right_prod[i] * left_prod[i];

        ans[0] = 1;
        for(int i=1; i<n; i++)
            ans[i] = ans[i-1]*nums[i-1];

        int right = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};

int main(){
    vector<int> nums{1,2,3,4};
    Solution s;
    vector<int> res = s.productExceptSelf(nums);
    for(int x: res)
        cout<<x<<endl; 
}