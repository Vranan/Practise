#include<bits/stdc++.h>
using namespace std;



class MyStack {
private: 
	queue<int> q1;
	queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	if (q1.size() == 0 && q2.size() == 0)
    		q1.push(x);
		else if (q1.size())
			q1.push(x);
		else
			q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int i = 1, qbck, sz;
    	if (q1.size()) {
    		sz = q1.size();
    		while((i++) < sz) {
    			q2.push(q1.front());
    			q1.pop();
			}
			qbck = q1.front();
			q1.pop();
		} else if (q2.size()) {
			sz = q2.size();
			while((i++) < sz) {
    			q1.push(q2.front());
    			q2.pop();
			}
			qbck = q2.front();
			q2.pop();
		}
        return qbck;
    }
    
    /** Get the top element. */
    int top() {
        if (!q1.empty()) {
        	return (q1.back());
        }
        else if (!q2.empty())
        	return (q2.back());
        else 
        	return 2147483647;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    	if (q1.empty() && q2.empty())
    		return true;
    	
        return false;
    }
};

int main() {
	MyStack stack;
	stack.push(1);
	stack.push(2);  
	stack.push(3);
	//cout << "M1.1 top = " << stack.top() << endl;
	int pop = stack.pop();
	// cout << "M1. pop = " << pop << endl;
	// cout << "M2.1 top = " << stack.top() << endl;
	pop = stack.pop(); 
	// cout << "M2. pop = " << pop << endl;
	// cout << "M3.1 top = " << stack.top() << endl;
	pop = stack.pop();
	// cout << "M3. pop = " << pop << endl;
	bool st = stack.empty();
	// cout << "M4. st = " << st << endl;
	return 0;
}


