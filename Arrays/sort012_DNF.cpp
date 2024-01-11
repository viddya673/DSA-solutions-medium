#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //DNF Algorithm
        int n = nums.size();
        int low=0, mid=0, high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){
    vector<int> nums{2, 2, 2, 2, 1, 0, 1, 1, 0};
    Solution s;
    s.sortColors(nums);
    for(int n: nums)
        cout<<n<<endl;
}
