// Problem: https://neetcode.io/problems/daily-temperatures?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        if(temperatures.size()==1){
            result[0]=0;
            return result;
        }

        // Handle case when array size is greater than 1
        int index;
        stack<int> st;
        st.push(0);
        for(int curr=1; curr<temperatures.size(); curr++){
            while(!st.empty() && temperatures[curr] > temperatures[st.top()]){
                index=st.top();
                result[index]=curr-index;
                st.pop();
            }
            st.push(curr);
        }

        // Empty the stack
        while(!st.empty()){
            index=st.top();
            result[index]=0;
            st.pop();
        }

        return result;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
