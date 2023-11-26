#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;
        //put all the array elements into set:
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        //Find the longest sequence:
        for (auto it : st) {
            //if 'it' is a starting number:
            if (st.find(it - 1) == st.end()) {
                //find consecutive numbers:
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

int main(){
    vector<int> nums{5, 100, 1, 3, 2, 4, 200};
    Solution s;
    cout<<s.longestConsecutive(nums);
}