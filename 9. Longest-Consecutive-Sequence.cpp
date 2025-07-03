#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/longest-consecutive-sequence?list=neetcode150 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a lookup map - hashing
        unordered_set<int> s;
        for(int n:nums) {
            s.insert(n);
        }

        // keep track of already visited elements
        unordered_set<int> visited;

        int count, curr, maxcount=0;
        for(int n:nums){
            count=0;

            // Check only if 'n' is not already visited, to avoid checking for already checked elements
            if(!visited.count(n)){
                // Find the number of consecutive elements before element 'n'
                curr=n;
                while(s.count(curr)) {
                    visited.insert(curr);
                    count++;
                    curr--;
                }

                // Find the number of consecutive elements after element 'n'
                curr=n+1;
                while(s.count(curr)) {
                    visited.insert(curr);
                    count++;
                    curr++;
                }

                if(count>maxcount)
                    maxcount=count;
            }
        }

        return maxcount;
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
