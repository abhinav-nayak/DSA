// Problem: https://neetcode.io/problems/find-target-in-rotated-sorted-array?list=neetcode150 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Each time we cut nums into half, we gte one sorted half and another unsorted half
        int l=0, r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(target==nums[mid])
                return mid;

            if(nums[l]<=nums[mid]){
                // Indicates left sub-array is sorted
                if(target<=nums[mid] && target>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else{
                // Indicates right sub-array is sorted
                if(target>=nums[mid] && target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }

        return -1;
    }
};

// Time complexity: O(log n)
// Space complexity: O(1)
