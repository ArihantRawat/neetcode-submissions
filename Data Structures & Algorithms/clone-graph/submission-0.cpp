/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return NULL;
        }
        map<Node*, Node*> oldToNew;
        return dfs(node,oldToNew);
        
    }
    Node* dfs(Node* node, map<Node*,Node*>& oldToNew) {
        if(oldToNew.contains(node)){
            return oldToNew[node];
        }
        Node* res = new Node(node->val);
        oldToNew[node] = res;
        for(int i=0;i<node->neighbors.size();i++) {
            res->neighbors.push_back(dfs(node->neighbors[i],oldToNew));
        }
        return res;
    }
};
