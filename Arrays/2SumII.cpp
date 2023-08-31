/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        int l=0, h=numbers.size()-1;
        while(l<h  && h>=0){
            int sum = numbers[l]+numbers[h];
            if(sum==target){
                res = {l+1, h+1};
                break;
            }
            if(sum>target){
                h--;
            }else{
                l++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{2,7,11,15};
    Solution s;
    vector<int> res = s.twoSum(nums, 9);
    for(int r: res)
        cout<<r<<endl;
    return 0;
}