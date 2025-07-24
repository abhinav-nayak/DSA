// Problem: https://neetcode.io/problems/reorder-linked-list?list=neetcode150 

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
    void reorderList(ListNode* head) {
        // IMPORTANT: using fast slow pointers to determine the midpoint of linked list
        // Find start of 2nd half
        ListNode* midStart;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        midStart=slow->next;

        if(!midStart)
            return;

        // Reverse the 2nd half
        ListNode* front=midStart->next;
        midStart->next=NULL;
        ListNode* prev=midStart;
        midStart=front;
        while(midStart){
            front=midStart->next;
            midStart->next=prev;
            prev=midStart;
            midStart=front;
        }
        // tail of 1st half pointing to NULL
        slow->next=NULL;

        // Merge the 2 halves one by one
        ListNode* first=head;
        ListNode* second=prev;
        ListNode* temp1;
        ListNode* temp2;
        while(second){
            temp1=first->next;
            first->next=second;
            temp2=second->next;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
