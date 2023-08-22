#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> majority;
        int n = nums.size();
        for(int num: nums){
            if(majority[num] > n/2) return num;
            majority[num]++;
        }

        int maxi = n/2;
        for(auto element: majority){
            if (element.second > maxi) return element.first;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,2,1,1,1,2,2};
    cout<<s.majorityElement(nums);
}