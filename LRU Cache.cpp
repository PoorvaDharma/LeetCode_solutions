class LRUCache {
public:
    
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> hash;
    size_t c;
    
    LRUCache(int capacity) {
        this->c = capacity;
    }
    
    int get(int key) {
        //unordered_map<int, list<pair<int,int>>::iterator>::iterator it;
        auto it = hash.find(key);
        
        if(it==hash.end()) //not present
           return -1;
        
        //move the element in front in the list
        //transfer element from callee list at poisition pointed by it to calling list at posotion pointed by begin
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        
        auto it = hash.find(key);
        if(it!=hash.end()) // key is present change the value to new value and bring the element to front
        {
            it->second->second = value;
            l.splice(l.begin(),l,it->second);
            hash[key] = l.begin();
            return;
        }
        
        if(l.size()>=c)
        {
            int key = l.back().first;
            l.pop_back();
            hash.erase(key);
        }
        
        //l.push_front(make_pair(key,value));
        l.emplace_front(key,value);
        hash.emplace(key,l.begin());
        //hash[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
