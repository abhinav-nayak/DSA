// Problem: https://neetcode.io/problems/generate-parentheses?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, string& st, vector<string>& result){
        if(openCount==n && closeCount==n){
            result.push_back(st);
            return;
        }

        if(openCount<n){
            st += "(";
            backtrack(openCount+1, closeCount, n, st, result);
            st.pop_back();
        }
        if(closeCount<openCount){
            st += ")";
            backtrack(openCount, closeCount+1, n, st, result);
            st.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string st;
        vector<string> result;
        backtrack(0, 0, n, st, result);
        return result;
    }
};

// Time complexity: number of solutions * work done for each solution
//                : Catalan number * 2n
//                : 2nCn/(n+1) * 2n
//                : O(4^n/n^(3/2)) * O(n)
//                : O(4^n/n^(0.5))

// Space complexity: O(n)
