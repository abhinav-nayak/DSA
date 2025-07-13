// Problem: https://neetcode.io/problems/eating-bananas?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Min value of k = 1. Max value of k = max(piles)
        // So, k=[1, 2, ...., max(piles)].
        // For each value of k, we can compute time taken and check if it is less than h. This brute force solution has time complexity: O(n*max(piles)).
        // We can reduce time complexity using binary search approach.

        // Find max(piles)
        int maxP=piles[0];
        for(auto p: piles){
            maxP=max(p, maxP);
        }

        // Boundaries for binary search
        int l=1, r=maxP;
        int k, minK=maxP;
        while(l<=r){
            k=(l+r)/2;
            int t=0;
            for(int p:piles){
                t+=p/k;
                if(p%k>0)
                    t++;
            }
            if(t<=h){
                r=k-1;
                minK=min(k, minK);
            }
            else if(t>h)
                l=k+1;
        }

        return minK;
    }
};

// Time complexity: O(n*log(max(piles)))
// Space complexity: O(1)
