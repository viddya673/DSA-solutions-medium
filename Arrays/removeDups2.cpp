#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(i<n-2 && nums[i]==nums[i+2]) continue;
            else{
                nums[c++] = nums[i];
            }
        }
        return c++;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1,1,2,2,3};
    int len = s.removeDuplicates(nums);
    for(int i=0; i<len; i++){
        cout<<nums[i]<<endl;
    }
}