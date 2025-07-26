// Problem: https://neetcode.io/problems/merge-k-sorted-linked-lists?list=neetcode150 
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
    // Conquer - merge 2 sorted lists
    ListNode* conquer(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;

        ListNode dummy;
        ListNode* prev=&dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                prev->next=l1;
                prev=l1;
                l1=l1->next;
                prev->next=NULL;
            }
            else{
                prev->next=l2;
                prev=l2;
                l2=l2->next;
                prev->next=NULL; 
            }
        }
        if(l1)
            prev->next=l1;
        if(l2)
            prev->next=l2;
        return dummy.next;
    }

    // Divide
    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        // Base conditions
        if(l>r)
            return NULL;
        if(l==r)
            return lists[l];

        int mid = (l+r)/2;
        ListNode* l1=divide(lists, l, mid);
        ListNode* l2=divide(lists, mid+1, r);

        return conquer(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        // Divide and conquer using recursion. Space complexity using recursion is less than iterative method.
        return divide(lists, 0, lists.size()-1);
    }
};

// Time complexity: O(n*logk)
// Space complexity: O(logk)
// where k is the total number of lists and n is the total number of nodes across k lists.
