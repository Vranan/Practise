#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> s1, s2;
        
        while(headA != NULL) {
            s1.push(headA);
            cout << "headA->val = " << headA->val << endl;
            headA = headA->next;
        }
        
         while(headB != NULL) {
            s2.push(headB);
            cout << "headB->val = " << headB->val << endl;
            headB = headB->next;
        }
        
        cout << "s.top() = " << s1.top() << ", s2.top() = " << s2.top() << endl;
        ListNode *t1 = NULL;
        while(!s1.empty() && !s2.empty()) {
            if (s1.top() == s2.top())
            	t1 = s1.top();
            else
                return t1;
            
            s1.pop();
            s2.pop();
        }
        
        return t1;
        
}

int main() {
	ListNode *h1 = new ListNode(1);
	ListNode *h2 = new ListNode(1);
	ListNode *h = getIntersectionNode(h1,h2);
	cout << "h->val = " << h->val << endl;
	return 0;
}
