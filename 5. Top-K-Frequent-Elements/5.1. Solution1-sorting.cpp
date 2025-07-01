#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Iterate through nums and record count of each number.
        unordered_map<int, int> m;
        for (int n:nums) {
            m[n]++;
        }

        // Form the vector so that we can sort it
        vector<pair<int, int>> vec;
        for(auto p:m) {
            vec.push_back({p.second, p.first});
        }

        // Sort the vector
        sort(vec.rbegin(), vec.rend());

        // Collect the result
        vector<int> result;
        for(auto p:vec){
            result.push_back(p.second);
            if (result.size() == k) {
                return result;
            }
        }
    }
};

// Time complexity: O(n logn)
// Space complexity: O(n)