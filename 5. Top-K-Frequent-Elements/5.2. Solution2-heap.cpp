#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Calculate each elements frequency
        unordered_map<int, int> m;
        for(int n:nums){
            m[n]++;
        }

        // Push all elements into priority queue/ heap while popping when size reaches k.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(auto p:m) {
            heap.push({p.second, p.first});
            if (heap.size()>k) {
                heap.pop();
            }
        }

        // Form the result vector
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;
    }
};

// Time complexity: O(n log k)
// Space complexity: O(n+k)