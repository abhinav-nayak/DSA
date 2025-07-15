// Problem: https://neetcode.io/problems/time-based-key-value-store?list=neetcode150 

#include<bits/stdc++.h>

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> keyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // Store it in keyStore - O(1)
        keyStore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto vec=keyStore[key];
        // Apply binary search logic - O(log n)
        int l=0, r=vec.size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(timestamp==vec[mid].first)
                return vec[mid].second;
            else if(timestamp>vec[r].first)
                return vec[r].second;
            else if(timestamp<vec[mid].first)
                r=mid-1;
            else if(timestamp>vec[mid].first){
                l=mid+1;
                if(timestamp<vec[l].first)
                    return vec[mid].second;
            }
        }

        return "";
    }
};

// Time complexity: O(1) for set, O(log n) for get
// Space complexity: O(m*n)
// where n is total number of values associated with a key and m is the total number of keys.
