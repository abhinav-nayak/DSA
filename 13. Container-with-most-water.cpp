#include<bits/stdc++.h>

// Problem: https://neetcode.io/problems/max-water-container?list=neetcode150 

class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 2 pointer converging approach
        int i=0, j=heights.size()-1;
        int maxArea=0, area, minHeight;
        while(i<j){
            minHeight = min(heights[i], heights[j]);
            area=(j-i)*minHeight;
            if(area>maxArea)
                maxArea=area;
            if(minHeight==heights[i])
                i++;
            else
                j--;            
        }

        return maxArea;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
