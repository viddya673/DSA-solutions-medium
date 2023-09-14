#include <iostream>
#include <vector>
using namespace std;

void deleteRoot(vector<int>& heap){
    int n = heap.size()-1;
    heap[1] = heap[n];
    heap.erase(heap.begin()+n);

    int i=1;
    while(i<n-1){
        int left = 2*i;
        int right = 2*i + 1;

        if(heap[i]<heap[left] || heap[i]<heap[right]){
            int swap_idx;
            if(heap[left]<heap[right]){
                swap_idx = right;
            }
            else{
                swap_idx = left;
            } 
            swap(heap[i], heap[swap_idx]);
            i = swap_idx; 
        }else{
            return;
        }
    }

}

int main(){
    vector<int> heap = {0, 40, 30, 10, 20, 15};
    deleteRoot(heap);

    for(int val: heap)
        cout<<val<<endl;
}