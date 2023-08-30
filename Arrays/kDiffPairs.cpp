#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> mp;
        int n = nums.size();

        for(int num:nums)
            mp[num]++;

        for(auto m: mp){
            if(k==0){
                if(m.second>1)
                    res++;
            }
            else if(mp.find(m.first+k)!=mp.end())
                res++;
        }
        return res;
    }
};

int main(){
    vector<int> nums{3,1,4,1,5};
    Solution s;
    cout<<s.findPairs(nums, 2);
}