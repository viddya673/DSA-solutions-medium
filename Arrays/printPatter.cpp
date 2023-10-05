#include <iostream>
using namespace std;

int main() {
    int N = 4;

    for(int i=0; i<N; i++){
        int times = i;
        int remain = N-times;
        while(times>0){
            cout<<N-times;
            times--;
        }
        while(remain>0){
            cout<<N;
            remain--;
        }
        cout<<endl;
    }

    return 0;
}
