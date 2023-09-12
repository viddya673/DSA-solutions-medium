#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> distinctSubarray(vector<int> arr, int k){
    int n = arr.size();
    int start=0;
    int end=-1;
    set<int> temp;
    vector<int> res;

    for(int i=0; i<n; i++){
        if(temp.size()==k){
            end=i-1;
            break;
        } 

        if(temp.count(arr[i]) && temp.size()<k){
            start=i;
            temp.clear();
            temp.insert(arr[start]);
            continue;
        }

        temp.insert(arr[i]);
    }

    if(end!=-1)
        res={start, end};

    return res;
}


int main() {
    vector<int> arr = {1, 2, 2, 1, 3, 4, 1, 3};
    int sum = 4;

    vector<int> res = distinctSubarray(arr, sum);
    
    if (res.empty()) {
        cout << "No subarray found with the target sum." << endl;
    } else {
        for(int x: res)
            cout<<x<<endl;
    }
    return 0;
}