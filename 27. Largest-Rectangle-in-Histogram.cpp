// Problem: https://neetcode.io/problems/largest-rectangle-in-histogram?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        int h, area;
        stack<pair<int, int>> st;
        for(int i=0; i<heights.size(); i++){
            if(st.empty() || heights[i]>=st.top().second){
                st.push({i, heights[i]});
            }
            else{
                pair<int, int> p;
                int start=i;
                while(!st.empty() && st.top().second>heights[i]){
                    p=st.top();
                    h=p.second;
                    area=h*(i-p.first);
                    if(area>maxArea)
                        maxArea=area;
                    st.pop();
                    start=p.first;
                }
                st.push({start, heights[i]});
            }
        }

        // Analyse area for remaining elements in stack. Now, these are in increasing order of height only.
        while(!st.empty()){
            auto t=st.top();
            area=(heights.size()-t.first)*t.second;
            if(area>maxArea)
                maxArea=area;
            st.pop();
        }

        return maxArea;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
