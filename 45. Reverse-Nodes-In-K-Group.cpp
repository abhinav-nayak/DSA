// Problem: https://neetcode.io/problems/reverse-nodes-in-k-group?list=neetcode150 

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* lag=head;
        ListNode* lead=head;
        ListNode* prev=NULL;
        ListNode* kend=NULL;
        ListNode* newHead=NULL;

        while(lead){
            int n=k;
            while(lead && n>1){
                lead=lead->next;
                n--;
            }

            if(lead && n==1){
                // Found group of k elements between lead and lag (including both)
                ListNode* kstart=lag;
                ListNode* t;
                while(lag!=lead){
                    t=lag->next;
                    lag->next=prev;
                    prev=lag;
                    lag=t;
                }
                // Now lag==lead
                t=lag->next;
                lag->next=prev;
                prev=lag;

                if(kend)
                    kend->next=lead;
                else
                    // First iteration, set head
                    newHead=lead;

                lag=t;
                lead=lag;
                kstart->next=lead;

                kend=kstart;
            }
        }

        return newHead;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
