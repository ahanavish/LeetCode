class Solution {
private:
    typedef pair<string, float> edge;       //renamed pair as edge to use it directly in the next line
    typedef unordered_map<string, vector<edge>> adja;        //renamed map as adj
    adja adj;
public:
    float dfs(string nodes, string noded, float curr, float& res, vector<string>& marked) {
        if(nodes.compare(noded) == 0)       // in case of edge (i, i) 
            return 1;
        
        marked.push_back(nodes);
        
        float maxx = -1;
        for(const edge& succ : adj[nodes]) {
            if(find(marked.begin(), marked.end(), succ.first) == marked.end()) {    // already visited or not      
                if(succ.first.compare(noded) == 0)                                  //if destination is found
                    return succ.second;           
                marked.push_back(succ.first);           //if not found, push into marked so that we dont visit it again
                maxx = max(succ.second * dfs(succ.first, noded, curr, res, marked), maxx);
            } 
        }
        return maxx < 0 ? -1 : maxx;        //no path between src and dst - found negative value
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,                     vector<vector<string>>& queries) {
        int i = 0;
        for(const vector<string>& eq : equations) {                     //constructing arrays
            string fst = eq[0], snd = eq[1];            
            
            adja::iterator it = adj.find(fst);      //finds element, returns end if element is not found
            pair<string, float> arc = make_pair(snd, values[i]);        // construct arc
            if(it == adj.end())                     //not present yet, create new
                adj.insert({fst, vector<edge>()});   
            adj[fst].push_back(arc);                //already present in map, so just push back
                 
            it = adj.find(snd);                     //finds element, returns end if element is not found
            arc = make_pair(fst, 1 / values[i]);                        // construct reverse arc
            if(it == adj.end())                     //not present yet, create new
                adj.insert({snd, vector<edge>()}); 
            adj[snd].push_back(arc);                //already present in map, so just push back
            
            i++;
        }
        
        vector<double> ans;                                              //to store ans  
        for(const vector<string>& q : queries) {
            string i = q[0], j = q[1];
            if(adj.find(i) == adj.end() || adj.find(j) == adj.end())     //if either of vertices is not present
                ans.push_back(-1);
            else {   
                float res = 1.0; 
                vector<string> marked;
                res = dfs(i, j, 1, res, marked);
                ans.push_back(res);
            }
        }
        return ans;
    }
};