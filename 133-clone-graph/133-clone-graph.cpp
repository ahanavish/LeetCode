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
        if(node == NULL)
            return NULL;
        
        vector <Node*> vis(101, NULL);
        Node* root = new Node(node->val);
        vis[node->val]=root;
        dfs(node, root, vis);
        return root;
    }
    
    void dfs(Node* node, Node* root, vector <Node*>& vis){
        for(auto n : node->neighbors){
            if(vis[n->val]==NULL){
                Node* no = new Node(n->val);
                vis[n->val]=no;
                (root->neighbors).push_back(no);
                dfs(n, no, vis);
            }
            else
                (root->neighbors).push_back(vis[n->val]);
        }
    }
};