#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

int countStudents(vector<int>& arr, int pages){
    int n = arr.size();
    int students = 1;
    int pages_per_student = 0;

    for(int i=0; i<n; i++){
        if(pages_per_student+arr[i]<=pages){
            pages_per_student += arr[i];
        }else{
            students++;
            pages_per_student = arr[i];
        }
    }

    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m>n) return -1;
    
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low<=high){
        int mid = (high+low)/2;
        int students = countStudents(arr, mid);
        if(students>m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}

int main() {
    vector<int> arr {12, 34, 67, 90};
    cout<<findPages(arr, 4, 2);
}
