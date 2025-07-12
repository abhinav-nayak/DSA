// Problem: https://neetcode.io/problems/validate-parentheses?list=neetcode150 

#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(string s) {
        char stackTop;
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else if(c==')' || c=='}' || c==']'){
                if(st.empty())
                    // Indicates no corresponding opening bracket
                    return false;
                stackTop = st.top();
                if((stackTop=='(' && c==')') || (stackTop=='{' && c=='}')|| (stackTop=='[' && c==']'))
                    st.pop();
                else
                    return false;
            }
        }

        if(!st.empty())
            // Indicates there are opening brackets without closing
            return false;
        return true;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
