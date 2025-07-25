/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Problem: https://neetcode.io/problems/copy-linked-list-with-random-pointer?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Corner case
        if(!head)
            return head;

        // First pass: (i) Create new nodes (ii) maintain hash map
        Node* newHead=NULL;
        Node* prev=NULL;
        Node* oldHead=head;
        unordered_map<Node*, Node*> addressMap;
        while(oldHead){
            Node* temp=new Node(oldHead->val);
            addressMap[oldHead]=temp;
            if(newHead==NULL)
                newHead=temp;
            if(prev)
                prev->next=temp;
            prev=temp;
            oldHead=oldHead->next;
        }
        prev->next=NULL;

        // Second pass: Set random pointers for each new node
        Node* p=newHead;
        Node* h=head;
        while(p && h){
            p->random=addressMap[h->random];
            p=p->next;
            h=h->next;
        }

        return newHead;      
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
