#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/three-integer-sum?list=neetcode150

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the input - helps in filtering duplicates
        sort(nums.begin(), nums.end());

        // Create lookup map - hashing
        unordered_map<int, int> lookup;
        for(int n:nums) {
            lookup[n]++;
        }

        // This is extension of 2 sum problem. In loop, solve for 2 sum
        int target, temp, count;
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++){
            lookup[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            target = 0-nums[i];

            // Solve 2 sum
            for(int j=i+1; j<nums.size(); j++){
                lookup[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                count = lookup[target-nums[j]];
                if(count>0){
                    result.push_back({nums[i], nums[j], target-nums[j]});
                }
            }

            for(int j=i+1; j<nums.size(); j++)
                lookup[nums[j]]++;
        }

        return result;
    }
};

// Time complexity: O(n^2)
// Space complexity: O(n)
