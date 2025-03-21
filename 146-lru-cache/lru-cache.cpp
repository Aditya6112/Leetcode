class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int val=mp[key].second;
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first=dll.begin();
        }else{
            dll.push_front(key);
            mp[key].first=dll.begin();
            mp[key].second=value;
            capacity--;
        }
        if(capacity<0){
            mp.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */