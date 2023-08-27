#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int winSum=0, minLength=INT_MAX, start=0;
        int i=1;
        for(int i=0; i<nums.size(); i++){
            winSum += nums[i];

            while(winSum>=target){
                minLength = min(minLength, (i-start+1));
                winSum -= nums[start];
                start++;
            }
        }
        return (minLength==INT_MAX) ? 0 : minLength;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;
    cout<<s.minSubArrayLen(target,  nums);
    return 0;
}