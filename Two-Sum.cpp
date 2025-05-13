#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/two-integer-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // Using unordered map for hashing
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])==m.end()){
                m.insert({nums[i], i});
            }

            // Check if there is possibility to form a pair that sums upto target
            auto possible_target = m.find(target-nums[i]);
            if(possible_target != m.end()){
                if (i==(*possible_target).second)
                    continue;
                else if (i<(*possible_target).second) {
                    result.push_back(i);
                    result.push_back((*possible_target).second);
                }
                else {
                    result.push_back((*possible_target).second);
                    result.push_back(i);
                }
                return result;
            }
        }
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
