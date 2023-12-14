#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites)
{
    vector<int> result;
    vector<int> indegree(numCourses+1, 0);
    vector<vector<int>> adj(numCourses+1);
    for(auto pre: prerequisites){
        adj[pre.second].push_back(pre.first);
        indegree[pre.first]++;
    }

    queue<int> q;
    for(int i=1; i<=numCourses; i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int neighbour: adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) q.push(neighbour);
        }
    }

    if(result.size()-1==numCourses)
        return result;
    return {};
}

int main() {

    vector<pair<int, int>> prerequisites;
    prerequisites.push_back({1, 1});
    prerequisites.push_back({2, 1});
    prerequisites.push_back({2, 2});
    prerequisites.push_back({2, 3});
    prerequisites.push_back({3, 3});
    prerequisites.push_back({3, 4});
	
	vector<int> ans = findSchedule(4, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}