// Problem: https://neetcode.io/problems/car-fleet?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Create a vector so that it can be sorted
        vector<pair<int, int>> cars;
        pair<int, int> temp;
        for(int i=0; i<position.size(); i++){
            temp={position[i], speed[i]};
            cars.push_back(temp);
        }

        // Sort based on position
        sort(cars.rbegin(), cars.rend());

        stack<float> st;
        for(auto p:cars){
            auto t=(float)(target-p.first)/p.second;
            if(st.empty()){
                st.push(t);
                continue;
            }

            if(t>st.top())
                st.push(t);
        }

        return st.size();
    }
};

// Time complexity: O(n*logn) - for sorting
// Space complexity: O(n)
