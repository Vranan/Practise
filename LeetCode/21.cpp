#include<bits/stdc++.h>
using namespace std;

/*
	Merge two sorted linked lists and return it as a new list. 
	The new list should be made by splicing together the nodes of the first two lists.
*/


class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(INT_MIN);
        ListNode* last = head;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                last->next = l2;
                l2 = l2->next;
            } 
            last = last->next;
        }
        last->next = (l1!=NULL) ? l1 : l2;
            
        return head->next;
        
            
    }
};
