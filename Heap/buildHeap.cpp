#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int i, int n){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<=n && heap[left]>heap[largest])
        largest = left;
    if(right<=n && heap[right]>heap[largest])
        largest = right;    
    
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify(heap, largest, n);
    }
}

void buildHeap(vector<int>& heap, int n){
    for(int i=n/2; i>0; i--){
        heapify(heap, i, n);
    }
}

int main(){
    vector<int> heap = {0, 10, 30, 50, 20, 35, 15};
    buildHeap(heap, heap.size()-1);

    for(int val: heap)
        cout<<val<<endl;
}