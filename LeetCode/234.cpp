#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        ListNode* start = head;
        
        while (start != NULL) {
            st.push(start->val);
            start = start->next;
        }
        
        while (head != NULL) {
            if (st.top() != head->val)
                return false;
            
            st.pop();
            head = head->next;
        }
        
        return true;
        
    }
