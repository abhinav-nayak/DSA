// Problem: https://neetcode.io/problems/lru-cache?list=neetcode150 

#include<bits/stdc++.h>

class LRUCache {
    // hash map to keep a map of key to value and node
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    // Inbuild doubly linked list
    list<int> linkedList;

    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            linkedList.erase(cache[key].second);
            linkedList.push_back(key);
            cache[key].second=--linkedList.end();
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // If key already exits
        if(cache.find(key)!=cache.end()){
            linkedList.erase(cache[key].second);
        }

        linkedList.push_back(key);
        cache[key]={value, --linkedList.end()};

        if(cache.size()>capacity){
            int k=linkedList.front();
            linkedList.pop_front();
            cache.erase(k);
        }
    }
};

// Time complexity: O(1) for put() and get()
// Space complexity: O(n)
