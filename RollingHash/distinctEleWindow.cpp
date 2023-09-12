#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> distinctEleWindow(vector<int> arr, int k){
    map<int, int> mp;
    vector<int> res;
    int n = arr.size();
    int start = 0;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;

        if(i-start+1==k){
            res.push_back(mp.size());
            if(mp[arr[start]]>1)
                mp[arr[start]]--;
            else
                mp.erase(arr[start]);
            start++;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 3, 1, 1, 3};
    int sum = 4;

    vector<int> res = distinctEleWindow(arr, sum);
    
    if (res.empty()) {
        cout << "No subarray found with the target sum." << endl;
    } else {
        for(int x: res)
            cout<<x<<endl;
    }
    return 0;
}