// Problem: https://neetcode.io/problems/add-two-numbers?list=neetcode150 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1, val2;
        int carry=0;
        int sum;

        ListNode* dummy=new ListNode();
        ListNode* prev=dummy;
        ListNode* p;
        while(l1 or l2){
            p=new ListNode();
            val1=l1?l1->val:0;
            val2=l2?l2->val:0;
            sum=val1+val2+carry;
            p->val=sum%10;
            carry=sum/10;
            prev->next=p;
            prev=p;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }

        // If carry is left after addition
        if(carry!=0){
            p=new ListNode(carry);
            prev->next=p;
            prev=p;
        }
        prev->next=NULL;

        return dummy->next;
    }
};

// Time complexity: O(m+n)
// Space complexity: O(max(m,n)) to store output
// Where m is the length of l1 and n is the length of l2.
