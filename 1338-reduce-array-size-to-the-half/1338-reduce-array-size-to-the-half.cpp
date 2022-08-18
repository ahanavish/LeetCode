class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int a : arr)
            m[a]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto p : m)
            pq.push({p.second, p.first});
        
        int n=0, size=pq.size();
        while(!pq.empty() && n<arr.size()/2){
            n += pq.top().first;
            pq.pop();
        }
        
        return size-pq.size();
    }
};