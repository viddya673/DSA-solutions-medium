#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

private: priority_queue<int, vector<int>, greater<int>> minHeap;
         priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num<=maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return maxHeap.top()/2.0 + minHeap.top()/2.0;
        return maxHeap.top();
    }
};

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout<<obj->findMedian()<<endl;
    obj->addNum(3);
    cout<<obj->findMedian()<<endl;

}