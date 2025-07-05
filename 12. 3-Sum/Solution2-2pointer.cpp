#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/three-integer-sum?list=neetcode150

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // To solve 2 sum using 2 pointer we need the array to be sorted
        sort(nums.begin(), nums.end());

        int target, x, y, sum;
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            target = 0-nums[i];

            x=i+1;
            y=nums.size()-1;
            while(x<y){
                sum = nums[x]+nums[y];
                if(sum>target)
                    y--;
                else if(sum<target)
                    x++;
                else{
                    result.push_back({nums[i], nums[x], nums[y]});
                    x++; y--;
                    // Important edgecase
                    while(x<y && nums[x]==nums[x-1])
                        x++;
                }
            }
        }

        return result;
    }
};

// Time complexity: O(n^2)
// Space complexity: O(log n) -> for sorting
