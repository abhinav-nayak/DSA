#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/duplicate-integer 

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Using unordered map for hashing
        // We can use unordered set as well
        unordered_map<int, int> m;

        // Iterate through nums and check if duplicate exists
        for(auto n:nums){
            if(m.find(n) != m.end())
                return true;
            else{
                m.insert({n, 1});
            }
        }
        return false;
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
