#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 1, n=citations.size();
        for(int i=n-1; i>=0; i--){
            if(citations[i]>=ans) ans++;
            else break;
        }
        return --ans;
    } 
};


int main(){
    vector<int> nums{3,0,6,1,5};
    Solution s;
    cout<<s.hIndex(nums);
}