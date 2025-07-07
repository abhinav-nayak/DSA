// Problem: https://neetcode.io/problems/longest-repeating-substring-with-replacement?list=neetcode150 

#include<bits/stdc++.h>

int maxFreqInLookup(unordered_map<char, int> lookup){
    int maxFreq=0;
    for(auto p:lookup){
        if(p.second>maxFreq)
            maxFreq=p.second;
    }
    return maxFreq;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        bool valid;
        unordered_map<char, int> lookup;

        int maxLength=0;
        for(; r<s.length(); r++){
            lookup[s[r]]++;
            valid = (r-l+1) - maxFreqInLookup(lookup) <= k ? true : false;
            if(valid){
                if((r-l+1)>maxLength)
                    maxLength=r-l+1;
            }
            else{
                lookup[s[l]]--;    
                l++;
            }
        }

        return maxLength;
    }
};

// Time complexity: O(n*m)
// Space complexity: O(m)
// Where n is the length of the string and m is the total number of unique characters in the string.
