#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int, int> majority;
        // int n = nums.size();
        // for(int num: nums){
        //     if(majority[num] > n/2) return num;
        //     majority[num]++;
        // }

        // int maxi = n/2;
        // for(auto element: majority){
        //     if (element.second > maxi) return element.first;
        // }
        // return 0;

        // Moore's Voting Algorithm
        int count=0, element;
        for(int num: nums){
            if(count==0){
                element=num;
                count++;
            }
            else if(element!=num){
                count--;
            }
            else count++;
        }

        int cnt=0;
        for(int num: nums){
            if(num==element) cnt++;
        }
        return (cnt>(nums.size()/2)) ? element : -1;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,2,1,1,1,3,3};
    cout<<s.majorityElement(nums);
}