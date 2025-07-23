// Problem: https://neetcode.io/problems/merge-two-sorted-linked-lists?list=neetcode150 

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode();;
        ListNode* prev=head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                prev->next=list1;
                prev=list1;
                list1=list1->next;
            }
            else{
                prev->next=list2;
                prev=list2;
                list2=list2->next;
            }
        }

        // Copy left over elements from list1
        while(list1){
            prev->next=list1;
            prev=list1;
            list1=list1->next;
        }

        // Copy left over elements from list2
        while(list2){
            prev->next=list2;
            prev=list2;
            list2=list2->next;
        }

        // Deallocate the memory
        prev=head->next;
        delete head;
        return prev;
    }
};

// Time complexity: O(m+n)
// Space complexity: O(1)
