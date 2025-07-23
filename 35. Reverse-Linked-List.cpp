// Problem: https://neetcode.io/problems/reverse-a-linked-list?list=neetcode150 

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
    ListNode* reverseList(ListNode* head) {   
        // Handle case where linked list length is 0 or 1 
        if(head==NULL || head->next==NULL)
            return head;

        // Linked list size is atleast 2 from here
        ListNode* temp=head;
        ListNode* front;
        head=head->next;
        temp->next=NULL;

        // Traverse the linked list and change the pointers
        while(head != NULL){
            front=head->next;
            head->next=temp;
            temp=head;
            head=front;
        }
        return temp;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)