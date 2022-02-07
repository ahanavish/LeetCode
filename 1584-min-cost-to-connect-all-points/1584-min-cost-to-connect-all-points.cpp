class edges{
public: 
    int point1, point2, cost;
    edges(int point1, int point2, int cost) : point1(point1), point2(point2), cost(cost){ }
};

bool operator< (const edges& edge1, const edges& edge2){
    return edge1.cost > edge2.cost;
}
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        
        int size=points.size();
        vector <bool> vis(size, false);
        priority_queue <edges> pq;
        for(int j=1; j<size; j++){
            int x1=points[0][0], x2=points[j][0], y1=points[0][1], y2=points[j][1];
            int d=abs(y2-y1)+abs(x2-x1);
            edges edge(0, j, d);
            pq.push(edge);
        }
        vis[0]=true;
        
        int count=size-1;
        int result=0;
        while(!pq.empty() && count>0){
            edges edge = pq.top();
            pq.pop();
            if(!vis[edge.point2]){
                vis[edge.point2]=true;
                result += edge.cost;
                count++;
                for(int j=0; j<size; j++){
                    if(j==edge.point2)
                        continue;
                    int x1=points[edge.point2][0], x2=points[j][0], y1=points[edge.point2][1], y2=points[j][1];
                    int d=abs(y2-y1)+abs(x2-x1);
                    edges edgee(edge.point2, j, d);
                    pq.push(edgee);
                }
            }
        }
        return result;
    }
};