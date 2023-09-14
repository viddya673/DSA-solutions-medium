/*Find the target in a sorted andd rotated array*/
#include <iostream>
#include <vector>
using namespace std;

int findTarget(vector<int> nums, int target){
    int n = nums.size();
    int l=0;
    int h=n-1;
    while(l<h){
        int mid = l + (h-l) / 2;

        if(target==nums[mid])
            return mid;

        if(nums[l]<nums[mid]){
            if(nums[l]>=target && target<nums[mid])
                h = mid-1;
            else
                l = mid+1;
        }else{
            if(nums[mid]<target && target<=nums[h])
                l = mid+1;
            else
                h = mid-1;
        }
        
    }
}

int main(){
    vector<int> nums = {120, 130, 40, 50, 90, 100, 110};
    int target = 100;

    cout<<findTarget(nums, target);
}