// Problem: https://neetcode.io/problems/permutation-string?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Corner case
        if(s2.size()<s1.size())
            return false;

        // Create hash table of s1
        unordered_map<int, int> hashS1;

        // Create a hash table for 1st substring of s2
        unordered_map<int, int> hashS2;
        for(int i=0; i<s1.size(); i++){
            hashS1[s1[i]-'a']++;
            hashS2[s2[i]-'a']++;
        }

        // Variable to count the number of matches
        // When matches==26, we have found a permutation
        int matches=0;
        for(int i=0; i<26; i++){
            if(hashS1[i]==hashS2[i])
                matches++;
        }
        if(matches==26)
            return true;

        int j=s1.size();
        cout<<"--Matches before loop: "<<matches<<endl;
        for(int i=0; i<s2.size() && j<s2.size(); i++, j++){
            if(hashS2[s2[i]-'a']==hashS1[s2[i]-'a'])
                matches--;
            hashS2[s2[i]-'a']--;
            if(hashS2[s2[i]-'a']==hashS1[s2[i]-'a'])
                matches++;

            if(hashS2[s2[j]-'a']==hashS1[s2[j]-'a'])
                matches--;
            hashS2[s2[j]-'a']++;
            if(hashS2[s2[j]-'a']==hashS1[s2[j]-'a'])
                matches++;

            cout<<"Matches during iteration "<<i<<" : "<<matches<<endl;
            if(matches==26)
                return true;
        }

        return false;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
