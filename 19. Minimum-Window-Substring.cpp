// Problem: https://neetcode.io/problems/minimum-window-with-characters?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        // corner case
        if(s.size() < t.size())
            return "";

        // create hashmap of string t
        unordered_map<char, int> hashT;
        for(char c:t){
            hashT[c]++;
        }

        // The number of characters whose count should match
        int requiredMatch = hashT.size();
        // The number of characters whose count is currently matching
        int currentMatch=0;
        int lFinal=0, rFinal=INT_MAX;

        // create another hashmap for substrings
        unordered_map<char, int> hashS;

        int l=0, r=0;
        for(r=0; r<s.size(); r++){
            // Find a substring which has all characters of t
            if(currentMatch!=requiredMatch && r<s.size()){
                hashS[s[r]]++;
                if(hashS[s[r]]==hashT[s[r]])
                    currentMatch++;
            }

            // If found, try if we can shorten the substring and achieve the result
            while(currentMatch==requiredMatch){
                if((r-l) < (rFinal-lFinal)){
                    lFinal=l;
                    rFinal=r;
                }
                cout<<"r: "<<r<<", l: "<<l<<endl;

                if(hashS[s[l]]==hashT[s[l]])
                    currentMatch--;
                hashS[s[l]]--;
                l++;
            }
        }

        if(!(lFinal==0 && rFinal==INT_MAX)){
            int len=rFinal-lFinal+1;
            return s.substr(lFinal, len);
        }
        return "";
    }
};

// Time complexity: O(n)
// Space complexity: O(m)
// Where n is the length of the string s and
// m is the total number of unique characters in the strings t and s.
