// Problem: https://neetcode.io/problems/median-of-two-sorted-arrays?list=neetcode150 

#include <bits/stdc++.h>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Making sure nums1 is smaller array always
        if(nums1.size()>nums2.size())
            swap(nums1, nums2);
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        // NUmber of elements on left side of merged array
        int sizeL=(size1+size2+1)/2;

        // Perform bianry search for nums1 array (smaller)
        int m, m2;
        int l=0, r=size1;
        double median;
        while(l<=r){
            m=(l+r)/2;
            // Index of partition on nums2 array
            m2=sizeL-m;
            int left1 = (m>0)?nums1[m-1]:INT_MIN;
            int right1 = m<nums1.size() ? nums1[m] : INT_MAX;
            int left2 = (m2>0)?nums2[m2-1]:INT_MIN;
            int right2 = m2<nums2.size() ? nums2[m2] : INT_MAX;

            if(left1<=right2 && left2<=right1){
                // Both left and right parts are correct and sorted
                int totalSize = (size1+size2);
                if(totalSize % 2 ==0){
                    // Merged array size would be even, so calculate median by taking average
                    // IMP: divide by 2.0 to get float value
                    median=(max(left1, left2) + min(right1, right2))/2.0;
                }
                else{
                    // Merged array size would be odd, so return middle element
                    median=max(left1, left2);
                }
                return median;
            }
            else if(left1>right2)
                r=m-1;
            else
                l=m+1;
        }

        return 0;
    }
};

// Time complexity: O(log(min(m,n)))
// Space complexity: O(1)
