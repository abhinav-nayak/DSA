#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/is-anagram 

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Not anagram if length is different
        if(s.length() != t.length())
            return false;
        
        // Using unordered map for hashing
        unordered_map<char, int> m;
        //Iterate over string s and make entry into hashmap
        for(auto c:s){
            if(m.find(c)!=m.end())
                m[c]++;
            else
                m[c]=1;
        }

        // Iterate over string t to update hashmap
        for(auto c:t){
            if(m.find(c)!=m.end()){
                m[c]--;
                if(m[c]<0)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
