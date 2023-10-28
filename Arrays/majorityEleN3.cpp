#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* Find the majority element occuring more than n/3 times in an array of size 'n'*/

/* Solution note:
   we know that the number of majority elements occuring more than n/3 can not be more that 2 times */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Moore's Voting Algorithm (modified)
        int count1=0, count2=0, element1, element2;
        for(int num: nums){
            if(count1==0 && element2!=num){
                element1=num;
                count1++;
            }else if(count2==0 && element1!=num){
                element2=num;
                count2++;
            }
            else if(element1==num) count1++;
            else if(element2==num) count2++;
            else count1--, count2--;
        }

        int cnt1=0, cnt2;
        for(int num: nums){
            if(num==element1) cnt1++;
            if(num==element2) cnt2++;
        }

        vector<int> res;
        int n = nums.size();
        if(cnt1 > (n/3)) res.push_back(element1);
        if(cnt2 > (n/3)) res.push_back(element2);

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{11,33,33,11,33,11};
    vector<int> res = s.majorityElement(nums);
    for(int n: res){
        cout<<n<<endl;
    }
}