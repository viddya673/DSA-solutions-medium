#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int max_weight){
    int r = values.size();
    vector<vector<int>> dp (r+1, vector<int>(max_weight+1));

}


int main(){
    int max_weight = 10;
    vector<int> weights = {1, 3, 4, 6};
    vector<int> values = {20, 30, 10, 50};
}