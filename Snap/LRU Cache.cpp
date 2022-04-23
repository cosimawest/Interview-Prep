class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache; // keeps track iterator pos/val of li item (::iterator so splice works)
    list<pair<int, int>> li; // keeps track of LRU (through order)
    int cap; // obvi
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) { 
        if(cache.find(key) == cache.end()) // key doesn't exist
            return -1;
        
        // move item to front of list
        li.splice(li.begin(), li, cache[key]);

        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) { // key exists
            // item already moved to front of li in get()
            cache[key]->second = value;
            return;
        }
        
        if(cache.size() == cap) { // key doesn't exist
            // removed LRU in li and cache
            cache.erase(li.back().first);
            li.pop_back();
        }
        
        // add new item to cache and li
        li.emplace_front(key, value);
        cache[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
