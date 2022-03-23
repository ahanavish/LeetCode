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
        
        vector <int> vis(101, 0);   //to keep track of nodes visited
        vector <Node*> add_nodes(101, NULL);    //to store address of each nodes
        
        Node* root = new Node(node->val);
        add_nodes[node->val]=root;
        
        queue <Node*> bfs;
        bfs.push(node);
        
        while(!bfs.empty()){
            Node* temp = bfs.front();
            bfs.pop();
            Node* new_node= add_nodes[temp->val];
                
            if(!vis[temp->val]){
                vis[temp->val] = 1;
                for(auto n: temp->neighbors){
                    if(add_nodes[n->val]==NULL){
                        Node* child = new Node(n->val);
                        new_node->neighbors.push_back(child);
                        add_nodes[n->val]=child;
                    }
                    else
                        new_node->neighbors.push_back(add_nodes[n->val]);
                    
                    bfs.push(n);
                }
            }
               
        }
        return root;
    }
};