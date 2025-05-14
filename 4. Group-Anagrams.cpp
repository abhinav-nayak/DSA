#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/anagram-groups 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        // Used for hashing
        unordered_map<string, vector<string>> m;

        for(string s:strs){
            vector<int> count(26, 0);
            for(char c:s){
                cout<<c<<" ";
                count[c-'a']++;
            }
            cout<<endl;

            // Form the hash key
            string key = to_string(count[0]);
            for(int i=1; i<26; i++){
                // Delimiter is important here, else few cases will fail
                key += "," + to_string(count[i]);
            }
            cout<<key<<endl;

            // Enter into hash map
            m[key].push_back(s);
        }

        for(auto p:m){
            result.push_back(p.second);
        }
        return result;
    }
};

// Time complexity - O(m*n)
// Space complexity - (i) Extra space: O(m) (ii) For output list: O(m*n)
