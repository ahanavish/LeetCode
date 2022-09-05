/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> curr;
            for(int i=0; i<size; i++){
                Node* node=q.front();
                q.pop();
                curr.push_back(node->val);
                for(auto child : node->children)
                    q.push(child);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

