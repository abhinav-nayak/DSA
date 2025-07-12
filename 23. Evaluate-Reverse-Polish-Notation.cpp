// Problem: https://neetcode.io/problems/evaluate-reverse-polish-notation?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result;
        int operand1, operand2;
        stack<int> st;
        for(string token:tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                operand2=st.top();
                st.pop();
                operand1=st.top();
                st.pop();
                if(token=="+")
                    result=operand1+operand2;
                else if(token=="-")           
                    result=operand1-operand2;
                else if(token=="*")           
                    result=operand1*operand2;
                else if(token=="/")           
                    result=operand1/operand2;
                st.push(result);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
