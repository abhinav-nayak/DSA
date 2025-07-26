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
    // Conquer method
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        // Corner case
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        
        // Merge lists when both are not NULL
        // Dummy head value
        ListNode* head=new ListNode();
        ListNode* prev=head;
        ListNode* l;
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

        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Using divide and conquer technique
        while(lists.size()>1){
            vector<ListNode*> mergedLists;
            // Dividing
            for(int i=0; i<lists.size(); i=i+2){
                ListNode* t=((i+1)<lists.size())?lists[i+1]:NULL;
                mergedLists.push_back(mergeList(lists[i], t));
            }
            lists=mergedLists;
        }
        return (lists.size()>0)?lists[0]:NULL;
    }
};

// Time complexity: O(n*logk) - each ndoe is merged logk times
// Space complexity: O(k) - for mergedLists
// where k is the total number of lists and n is the total number of nodes across k lists.
