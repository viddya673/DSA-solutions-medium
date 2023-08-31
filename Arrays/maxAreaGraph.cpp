#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, maxArea=INT_MIN;

        while(left<right){
            int currArea = min(height[left], height[right]) * (right-left);
            maxArea = max(currArea, maxArea);

            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(nums);
    return 0;
}