class MyHashMap {
public:
    vector<int> vec;
    MyHashMap() {
       vec = vector<int>(1,-1); 
    }
    
    void put(int key, int value) {
        if(vec.size() <= key) {
            vec.resize(key + 10, -1);
        }        
        vec[key] = value;
    }
    
    int get(int key) {
        if(vec.size() <= key) {
            vec.resize(key + 10, -1);
        } 
        if(vec.size() >= key) {
            return vec[key];
        }
        return -1;
    }
    
    void remove(int key) {
        if(vec.size() <= key) {
            vec.resize(key + 10, -1);
        }
        vec[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */