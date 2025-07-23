// Problem: https://neetcode.io/problems/linked-list-cycle-detection?list=neetcode150 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // If cycle exists, slow and fast pointers will meet for sure
        while(fast && fast->next){
            slow=slow->next;
            fast=(fast->next)->next;
            if(slow==fast)
                return true;
        }

        // If fast pointer reaches the end of list, that means no cycle exists
        return false;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
