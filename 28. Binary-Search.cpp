// Problem: https://neetcode.io/problems/binary-search?list=neetcode150 

// Function declaration
int binarySearch(int l, int r, vector<int>& nums, int target);

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};

int binarySearch(int l, int r, vector<int>& nums, int target){
    // Base condition
    if(l>r)
        return -1;

    int mid=(l+r)/2;
    if(target<nums[mid])
        return binarySearch(l, mid-1, nums, target);
    else if(target>nums[mid])
        return binarySearch(mid+1, r, nums, target);
    else
        return mid;
}

// Time complexity: O(logn)
// Space complexity: O(logn). Space complexity can be reduced to O(1) if binary search is implemented in iterative way.
