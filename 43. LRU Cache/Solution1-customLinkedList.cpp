// Problem: https://neetcode.io/problems/lru-cache?list=neetcode150 

#include<bits/stdc++.h>

class Node{
    public:
        int key;
        int val;
        Node* back;
        Node* front;

        // Constructor
        Node(int v): val(v), back(NULL), front(NULL){}
};

class LRUCache {
    // Doubly linked list for easily removing least recently used
    Node* left=NULL;
    Node* right=NULL;

    // insert method for doubly linked list
    void insert(Node* p){
        if(left==NULL && right == NULL){
            left=p;
            right=p;
            return;
        }

        if(left==p && right==p)
            return;

        right->front=p;
        p->back=right;
        right=p;
        right->front=NULL;
    }

    // remove method for doubly linked list
    void remove(Node* p){
        if(left==right){
            left=NULL;
            right=NULL;
            return;
        }

        if(p->back)
            p->back->front=p->front;
        else
            left=p->front;
        if(p->front)
            p->front->back=p->back;
        else
            right=p->back;
    }

    int capacity;
    // hash map for get and put while key exists
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* p=cache[key];
            remove(p);
            insert(p);
            return p->val;
        }
        cout<<"Get "<<key<<" successful";
        return -1;
    }
    
    void put(int key, int value) {
        // If key is found in cache, just update it
        if(cache.find(key)!=cache.end()){
            Node* p=cache[key];
            p->val=value;
            remove(p);
            insert(p);
            cout<<"Updated node with key: "<<key;
            return;
        }

        // Inset new key
        Node* t=new Node(value);
        t->key=key;
        insert(t);
        cache[key]=t;

        // If capacity excees, delete the least recently used (head of linked list)
        if(cache.size() > capacity){
            Node* x=left;
            remove(left);
            cache.erase(x->key);
            delete x;
        }

        cout<<"New node, key: "<<key<<" , value: "<<value<<" successful";
    }
};

// Time complexity: O(1) for get() and put()
// Space complexity: O(n)
