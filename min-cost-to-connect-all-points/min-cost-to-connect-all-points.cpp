class edges{
public: 
    int point1, point2, cost;       //declaring edges with 3 members
    edges(int point1, int point2, int cost) : point1(point1), point2(point2), cost(cost){}
};

bool operator<(const edges& edge1, const edges& edge2) {   // Overload the < operator for priority queue process
    return edge1.cost > edge2.cost;
}

class unionfind{        //most optimised unionfind procedure
private: 
    vector <int> rank;      
    vector <int> root;
public:
    unionfind(int size) : root(size), rank(size){
        for(int i=0; i<size; i++){
            rank[i] = 1;
            root[i] = i;
        }
    }
    
    int find(int x){
        if(x==root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionn(int x, int y){
        int rootx=find(x), rooty=find(y);
        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty])
                root[rooty] = rootx;
            else if(rank[rootx]<rank[rooty])
                root[rootx] = rooty;
            else{
                root[rooty] = x;
                rank[rootx]++;
            }
        }
    }
           
    bool connected(int x, int y){
       return find(x)==find(y);
    }
};
           
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()==0)            //if it is empty, return 0;
            return 0;
        int size=points.size();
        unionfind uf(size);         
        
        priority_queue <edges> pq;
        for(int i=0; i<points.size(); i++)
            for(int j=i+1; j<points.size(); j++){
                int x1=points[i][0], x2=points[j][0], y1=points[i][1], y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                edges edge(i, j, d);    //creating edge with point1, point2, cost
                pq.push(edge);          //putting edge in priority queue
            }
        
        int result=0;
        int edgeno=size-1;
        while(!pq.empty() && edgeno>0){ //if any of these conditions fail ,we cant move forward
            edges edge = pq.top();      
            pq.pop();
            if(!uf.connected(edge.point1, edge.point2)){
                uf.unionn(edge.point1, edge.point2);        //if points are not connected yet, connect them
                result += edge.cost;                        //thus adding it's cost in our result
                edgeno--;                                   //and updating no of edges needed further
            }            
        }
        
        return result;
    }
};