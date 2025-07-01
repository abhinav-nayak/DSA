#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Calculate the frequency
        unordered_map<int, int> m;
        for(int n:nums){
            m[n]++;
        }

        // Bucket sort inspiration
        vector<vector<int>> vec(nums.size() + 1);
        for(auto p:m){
            vec[p.second].push_back(p.first);
        }

        // Form the result
        vector<int> result;
        for(int i=nums.size(); i>0; i--){
            for(int j:vec[i]){
                result.push_back(j);
                if(result.size()==k)
                    return result;
            }
        }
    }
};

// Time complexity: O(n)
// Space complexity: O(n)