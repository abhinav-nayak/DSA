//Problem: https://neetcode.io/problems/longest-substring-without-duplicates?list=neetcode150

#include<bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int longest=0;
        unordered_set<char> lookup;

        while(r<s.length()){
            if(lookup.count(s[r])){
                // Important to move left pointer one by one
                lookup.erase(s[l]);
                l++;
            }
            else{
                lookup.insert(s[r]);
                longest= max(longest, r-l+1);
                r++;
            }
        }

        return longest;
    }
};

// Time comlexity: O(n)
// Space complexity: O(m)
// Where n is the length of the string and m is the total number of unique characters in the string.
