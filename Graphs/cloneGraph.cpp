#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class graphNode
{
    public:
        int data;
    vector<graphNode *> neighbours;
    graphNode()
    {
        data = 0;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> neighbours)
    {
        data = val;
        this->neighbours = neighbours;
    }
};

graphNode *cloneGraph(graphNode *node)
{
	unordered_map<graphNode*, graphNode*> mp;
	if(node){
		graphNode* newNode = new graphNode(node->data);
		mp[node] = newNode;
	}
	queue<graphNode*> q;
	q.push(node);

	while(!q.empty()){
		graphNode* curr = q.front();
		q.pop();
		for(auto nh: curr->neighbours){
			if(mp.find(nh)==mp.end()){
				graphNode* copy = new graphNode(nh->data);
				mp[nh] = copy;
				q.push(nh);
			}
			mp[curr]->neighbours.push_back(mp[nh]); 
		}
	}
	return mp[node];
}