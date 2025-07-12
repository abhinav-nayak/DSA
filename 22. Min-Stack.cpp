// Problem: https://neetcode.io/problems/minimum-stack?list=neetcode150 

#include<bits/stdc++.h>

class MinStack {
    stack<int> st;
    // Extra stack to hold information of min element.
    stack<int> minSt;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minSt.empty())
            minSt.push(val);
        else{
            if(val<minSt.top())
                minSt.push(val);
            else
                minSt.push(minSt.top());
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Time complexity: O(1) for all operations
// Space complexity: O(n)
