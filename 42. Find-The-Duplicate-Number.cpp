// Problem: https://neetcode.io/problems/find-duplicate-integer?list=neetcode150 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // With hashing, this can be solved in O(n) time and O(n) space complexity.

        // According to author: this problem is not very intuitive. If we have not seen this problem even once, it is tough to solve.
        // Floyd's algorithm is something that we have to memorize.

        // 2 challenges of this problem:
        // (i) Identifying that this is a linked list problem.
        // (ii) Using floyd's algorithm

        // If there is a duplicate in the vector and if we consider each element as pointer then it always forms a cycle in linked list.
        // Once we detect cycle, the beginning of the cycle is the duplicate element.
        // You can use Flyod's algorithm to find the beginning of the cycle.
        
        // Flyod's algorithm to find the beginning of the cycle:
        // As part of cycle detection, we will find a point where slow and fast pointers meet.
        // Move a new slow pointer from start of linked list and also move the existing slow pointer, both by 1 step each.
        // The point where these 2 slow pointers meet will be the beginning of the cycle.

        // Step 1: Cycle detection logic to find the point where slow and fast pointers meet.
        int slow=0, fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
                break;
        }

        // Step 2: Flyod's algorithm to find the beginning of the cycle.
        int slow2=0;
        while(true){
            slow=nums[slow];
            slow2=nums[slow2];
            if(slow==slow2)
                return slow;
        }
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
