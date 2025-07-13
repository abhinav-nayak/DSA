// Problem: https://neetcode.io/problems/find-minimum-in-rotated-sorted-array?list=neetcode150 

#include<bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;
        int mid, minVal=nums[0];
        while(l<=r){
            mid=(l+r)/2;

            // If array is already sorted, return leftmost element
            if(nums[l]<nums[r])
                return nums[l];

            // Base condition
            if((l-r==1) || (l-r==-1) || l==r){
                return min(nums[l], nums[r]);
            }
            else if(nums[l]<nums[mid])
                // Indicates left array is sorted
                l=mid+1;
            else
                // Indicates right array is sorted
                r=mid;
        }

        return minVal;
    }
};

// Time complexity: O(logn)
// Space complexity: O(1)
