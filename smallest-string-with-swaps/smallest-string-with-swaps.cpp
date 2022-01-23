class unionfind{        //most optimised way of implementing disjoint sets
    public: 
    int count;
    vector <int> root;
    vector <int> rank;
    unionfind(int n){
        count = n;
        root = vector <int> (n);
        rank = vector <int> (n);
        
        for(int i=0; i<n; i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    
    void unionset(int x, int y){        
        int rootx=find(x), rooty=find(y);
        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty])
                root[rooty]=rootx;
            else if(rank[rooty]>rank[rootx])
                root[rootx]=rooty;
            else{
                root[rooty]=rootx;
                rank[rootx]++;
            }
            count--;
        }
    }
    
    int find(int x){
        if(x==root[x])
            return root[x];
        return root[x]=find(root[x]);
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        if(pairs.size()==0)          //if there are no edges at all, we simply return back the string
            return s;
        
        unionfind uf(n);             //to create n-sized arrays(root, rank)
        
        for(auto pair: pairs)        //make the union of elements
            uf.unionset(pair[0], pair[1]);
        
        map<int, string> m;
        for(int i=0; i<n; i++){      //adding the char one by one in map corresponding to root
            int root = uf.find(i);
            uf.root[i] = root;
            m[root] += s[i];
        }
        
        if(uf.count==1){             //if the whole graph is connected, simply return string after sorting
            sort(s.begin(), s.end());
            return s;
        }
        
        for(auto pairs:m){           //if whole graph is not completely connected, sort the char in disconnected 
            int i=pairs.first;       // graphs individually
            string s=pairs.second;
            sort(s.begin(), s.end(), greater<char>());
            m[i]=s;
        }
        
        for(int i=0; i<n; i++){     //storing the back into the string
            int root=uf.find(i);
            s[i]=m[root].back();
            m[root].pop_back();
        }
        return s;                   //return the resultant string
    }
};