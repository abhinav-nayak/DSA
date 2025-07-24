// Problem: https://neetcode.io/problems/remove-node-from-end-of-linked-list?list=neetcode150 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // IMPORTANT: Using lead-lag pointers technique
        ListNode* lead=head;
        ListNode* lag=head;
        while(n!=0){
            lead=lead->next;
            n--;
        }

        if(lead==NULL){
            // Means it is a case of deleting 1st element
            ListNode* temp=head->next;
            delete head;
            return temp;
        }

        // When lead becomes NULL, we have to delete the node pointed by lag
        ListNode* prev=head;
        while(lead){
            lead=lead->next;
            prev=lag;
            lag=lag->next;
        }

        // Delete node
        prev->next=lag->next;
        delete lag;

        return head;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
