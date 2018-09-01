#include<bits/stdc++.h>
using namespace std;

class MinStack {
	
private:
    struct node{
		int val;
		struct node* next;
		struct node* prev;
    };
    node *t = NULL;
    node *bottom = NULL;
    int min = 0;

public:
   void push(int val) {
		node *new_node = new node;
		new_node->val = val;
		new_node->next = NULL;
		new_node->prev = NULL;
		if (t == NULL) {
			t = new_node;
			bottom = t;
		} else {
			node *itr = t;
			t->next = new_node;
			t = t->next;
			t->prev = itr;
		}
	}
	
	void pop() {
		if (t->prev == NULL) {
			t = NULL;
			return;
		}
			
		t = t->prev;
		t->next = NULL;
		return;
	}

	int top() {
		return (t->val);
	}

	int getMin() {
		node *snode = bottom;
		min = bottom->val;
		while(snode) {
			if (snode->val < min)
				min = snode->val;
			snode = snode->next;
		}
		return min;
	}
};



int main() {
	
	MinStack minStack;
	/*
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	int min = minStack.getMin();   //--> Returns -3.
	cout << "1. min = " << min << endl;
	minStack.pop();
	cout << "pop done" << endl;
	int top = minStack.top();     // --> Returns 0.
	cout << "2. top = " << top << endl;	
	min = minStack.getMin();  // --> Returns -2.
	cout << "3. min = " << min << endl;	
	*/
	
	minStack.push(2147483646);
	minStack.push(2147483646);
	minStack.push(2147483647);
	int top = minStack.top();
	cout << "1. top = " << top << endl;
	minStack.pop();
	cout << "1.1 pop" << endl;
	int min = minStack.getMin();
	cout << "2. min = " << min << endl;
	minStack.pop();
	cout << "2.1 pop" << endl;
	min = minStack.getMin();
	cout << "3. min = " << min << endl;
	minStack.pop();
	cout << "3.1 pop" << endl;
	minStack.push(2147483647);
	top = minStack.top();
	cout << "4. top = " << top << endl;
	min = minStack.getMin();
	cout << "5. min = " << min << endl;
	minStack.push(-2147483648);
	top = minStack.top();
	cout << "6. top = " << top << endl;
	min = minStack.getMin();
	cout << "7. min = " << min << endl;
	minStack.pop();
	cout << "7.1 pop" << endl;
	min = minStack.getMin();
	cout << "8. min = " << min << endl;
	return 0;
}



















/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
