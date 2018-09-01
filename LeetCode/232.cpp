#include<bits/stdc++.h>
using namespace std;

class MyQueue {
	
private: 
	stack<int> st1;
	stack<int> st2;
	int tval = 0;
	
public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!st2.empty()) {
        	st1.push(st2.top());
        	st2.pop();
		}
		if (st1.empty())
			tval = x;
			
		st1.push(x);
    }
    
    int pop() {
    	int sz = 0, i = 1, pval;
    	if (st2.empty()) {
    		sz = st1.size();
    		while((i++) < sz) { 
    			st2.push(st1.top());
    			tval = st1.top();
    			st1.pop();
			}
			pval = st1.top();
			st1.pop();
			return pval;
		}
			pval = st2.top();
			st2.pop();
			if (!st2.empty())
				tval = st2.top();
		
		return pval;
    }
    
    int peek() {
        return tval;
    }
    
    bool empty() {
        if (st1.size() == 0 && st2.size() == 0) {
        	return true;
        }
        return false;
    }
};
int main() {
    cout << "Inside Main" << endl;
    int pop, t;
    bool e;
    MyQueue obj;
    obj.push(1);
    obj.push(2);
    t = obj.peek();
    pop = obj.pop();
    t = obj.peek();
    pop = obj.pop();
    e = obj.empty();
    /* 
	obj.push(3);
    int p2 = obj.pop();
    //cout << p2 << endl;
    p2 = obj.pop();
    //cout << p2 << endl;
    p2 = obj.pop();
    //cout << p2 << endl;
    bool param_4 = obj.empty();
    //cout << param_4 << endl;
    */
	return 0;
}
