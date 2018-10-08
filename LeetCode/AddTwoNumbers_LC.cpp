/*
  Definition for singly-linked list. 
 
 Leetcode :: Question: Add Two Numbers 
 
 You are given two non-empty linked lists representing two non-negative integers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 An efficient solution is at the bottom of the page.
 
 */
 

#include <bits/stdc++.h>
using namespace std; 

struct ListNode {
  	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void itr (ListNode *node) {
	while (node) {
		cout << node -> val;
		node = node->next;
	}
	cout << endl;
}
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int carry = 0;
    	
    	ListNode *sumn = new ListNode(-1);
    	ListNode *top = sumn;
    	
    	while(l1 && l2) {	
        	int sum = l1->val + l2->val + carry;
        	carry = sum/10;
        	sumn->val = sum%10;
        	l1 = l1 -> next;
        	l2 = l2 -> next;
        	if (l1 || l2) {
        		sumn->next = new ListNode(-1);
        		sumn = sumn->next;
        	}
        }
        
        while(l1) {
        	int sum = l1->val+carry;
        	sumn->val = sum%10;
        	carry = sum/10;
        	l1 = l1->next;
        	if (l1) {
        		sumn->next = new ListNode(-1);
        		sumn = sumn->next;
        	} else 
        	    sumn -> next = NULL;
		}
		
		while(l2) {
			int sum = l2->val+carry;
			sumn->val = sum%10;
			carry = sum/10;
			l2 = l2 -> next;
			if (l2) {
				sumn->next = new ListNode(-1);
        		sumn = sumn->next;
        	} else
        		sumn -> next = NULL;
		}
		
		if (carry != 0) {
			sumn->next = new ListNode(carry);
			sumn = sumn->next;
		}
		sumn -> next = NULL;
		return top;
    }
};


int main() {
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(4);
	
	//l1 -> val = 2;
	l1 -> next = new ListNode(4);
	l1 -> next -> next  = new ListNode(3);
	l1 -> next -> next -> next = NULL;

	//l2 -> val = 4;
	l2 -> next = new ListNode(6);
	l2 -> next -> next  = new ListNode(5);
	l2 -> next -> next -> next = NULL;	
	
	cout << " l1" << endl;
	itr(l1);
	cout << " l2" << endl;
	itr(l2);
	
	Solution sol;
	ListNode *sum_f = new ListNode(-1);
	sum_f = sol.addTwoNumbers(l1, l2);
	cout << " final sum " << endl;
	itr(sum_f);
	
	
	return 0;
}




/* Efficient Solution from leetcode

public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}

*/
