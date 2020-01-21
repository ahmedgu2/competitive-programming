#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

class LRUCache {
public:
    
    gp_hash_table<int, int> m; 
    gp_hash_table<int, list<int>::iterator> kv;
    list<int> l;
    int cap = 0;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            auto it = kv.find(key);
            l.splice(l.begin(), l, it->second);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key] = value;
            update_list(key);
            return ;
        }
        if(m.size() == cap){
            int k = l.back();
            m.erase(k);
            l.pop_back();
            kv.erase(key);
        }
        update_list(key);
        m[key] = value;
    }
    
    void update_list(int key){
        auto it = kv.find(key);
        if(it != kv.end())
            l.splice(l.begin(), l, it->second);
        else
            l.push_front(key);
        kv[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */