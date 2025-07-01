#include <bits/stdc++.h>

using namespace std;

// Problem: https://neetcode.io/problems/string-encode-and-decode?list=neetcode150 

class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        int len;

        // To separate strings, add length of string and # before each string
        for(string s:strs){
            len = s.length();
            result += to_string(len) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int strLength;
        string indStringLen;

        int i, j, k;
        for(i=0; i<s.length();) {
            indStringLen="";
            // Could have used while loop as well
            for(j=i; s[j]!='#' && j<s.length(); j++) {
                indStringLen += s[j];
            }
            i=j+1;
            string indStr="";
            strLength = stoi(indStringLen);
            for(k=0; k<strLength; k++)
                indStr += s[i++];

            result.push_back(indStr);
        }

        return result;
    }
};

// Time complexity for both encode and decode: O(m)
// Space complexity for encode: O(m) (where m is the total length of all strings in the input vector)