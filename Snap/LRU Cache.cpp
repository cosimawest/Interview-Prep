class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    list<pair<int, int>> Lcache;
    int cap;
    

    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        Lcache.splice(Lcache.begin(), Lcache, cache[key]); // update list
        return cache[key]->second;
    }
    
    void put(int key, int value) {        
        if (get(key) != -1) { // if exists, replace value THATS IT (get function updates list)
            cache[key]->second = value;
            return;
        }

        if (cache.size() == cap) { // if !exists and cap, delete from map -> delete from list
            int delKey = Lcache.back().first;
            Lcache.pop_back();
            cache.erase(delKey);
        }
        // if !exists, 
        Lcache.emplace_front(key, value);
        cache[key] = Lcache.begin();
    }
};

// LIST.emplace_front => put item in front of list
// LIST.splice(where to put position, list2, key to find); => move item to position in list
// LIST.pop_back(); => remove last item in list
// MAP.erase(); => erase item in map

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    list<pair<int, int>> Lcache;
    int cap;
    

    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        Lcache.splice(Lcache.begin(), Lcache, cache[key]); // update list
        return cache[key]->second;
    }
    
    void put(int key, int value) {        
        if (get(key) != -1) { // if exists, replace value THATS IT (get function updates list)
            cache[key]->second = value;
            return;
        }

        if (cache.size() == cap) { // if !exists and cap, delete from map -> delete from list
            int delKey = Lcache.back().first;
            Lcache.pop_back();
            cache.erase(delKey);
        }
        // if !exists, 
        Lcache.emplace_front(key, value);
        cache[key] = Lcache.begin();
    }
};

// LIST.emplace_front => put item in front of list
// LIST.splice(where to put position, list2, key to find); => move item to position in list
// LIST.pop_back(); => remove last item in list
// MAP.erase(); => erase item in map

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    list<pair<int, int>> Lcache;
    int cap;
    

    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        Lcache.splice(Lcache.begin(), Lcache, cache[key]); // update list
        return cache[key]->second;
    }
    
    void put(int key, int value) {        
        if (get(key) != -1) { // if exists, replace value THATS IT (get function updates list)
            cache[key]->second = value;
            return;
        }

        if (cache.size() == cap) { // if !exists and cap, delete from map -> delete from list
            int delKey = Lcache.back().first;
            Lcache.pop_back();
            cache.erase(delKey);
        }
        // if !exists, 
        Lcache.emplace_front(key, value);
        cache[key] = Lcache.begin();
    }
};

// LIST.emplace_front => put item in front of list
// LIST.splice(where to put position, list2, key to find); => move item to position in list
// LIST.pop_back(); => remove last item in list
// MAP.erase(); => erase item in map

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    list<pair<int, int>> Lcache;
    int cap;
    

    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        Lcache.splice(Lcache.begin(), Lcache, cache[key]); // update list
        return cache[key]->second;
    }
    
    void put(int key, int value) {        
        if (get(key) != -1) { // if exists, replace value THATS IT (get function updates list)
            cache[key]->second = value;
            return;
        }

        if (cache.size() == cap) { // if !exists and cap, delete from map -> delete from list
            int delKey = Lcache.back().first;
            Lcache.pop_back();
            cache.erase(delKey);
        }
        // if !exists, 
        Lcache.emplace_front(key, value);
        cache[key] = Lcache.begin();
    }
};

// LIST.emplace_front => put item in front of list
// LIST.splice(where to put position, list2, key to find); => move item to position in list
// LIST.pop_back(); => remove last item in list
// MAP.erase(); => erase item in map

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    list<pair<int, int>> Lcache;
    int cap;
    

    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        Lcache.splice(Lcache.begin(), Lcache, cache[key]); // update list
        return cache[key]->second;
    }
    
    void put(int key, int value) {        
        if (get(key) != -1) { // if exists, replace value THATS IT (get function updates list)
            cache[key]->second = value;
            return;
        }

        if (cache.size() == cap) { // if !exists and cap, delete from map -> delete from list
            int delKey = Lcache.back().first;
            Lcache.pop_back();
            cache.erase(delKey);
        }
        // if !exists, 
        Lcache.emplace_front(key, value);
        cache[key] = Lcache.begin();
    }
};

// LIST.emplace_front => put item in front of list
// LIST.splice(where to put position, list2, key to find); => move item to position in list
// LIST.pop_back(); => remove last item in list
// MAP.erase(); => erase item in map

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
