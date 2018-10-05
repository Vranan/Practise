#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
void itr(ListNode* n) {
	while(n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

ListNode* reverseList(ListNode* head) {
	cout << "head->val = " << head->val << endl; 
        if (!head || !(head -> next))
            return head;
        
        ListNode* node = reverseList(head -> next);
        cout << "--------------- node->val = " << node->val << " -------------- " << endl;
        itr(node);
        cout << "head = " << head->val << endl;
        cout << "head->next = " << head->next->val << endl;
        
        head -> next -> next = head;
        
        cout << "head->next->next = " << head->next->next->val << endl;
        head -> next = NULL;
        return node;
}

int main() {
	ListNode* h = new ListNode(1);
	ListNode* top = h;
	h->next = new ListNode(2);
	h = h->next;
	h->next = new ListNode(3);
	h = h->next;
	h->next = new ListNode(4);
	h = h->next;
	h->next = new ListNode(5);
	h = h->next;
	ListNode* ref = reverseList(top);
	return 0;
}
