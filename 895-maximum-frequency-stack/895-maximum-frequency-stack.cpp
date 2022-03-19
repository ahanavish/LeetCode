class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>umap;
    int pos = 0;
    
    void push(int x) {
        umap[x]++;
        pq.push({umap[x],{pos++,x}});
    }
    
    int pop() {
        int x = pq.top().second.second;
        umap[x]--;
        pq.pop();
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */