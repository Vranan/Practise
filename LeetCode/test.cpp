#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;
	q.push(1);
	q.push(2);
	cout << q.front() << ", " << q.back() << endl;
	q.pop();
	cout << q.front() << ", " << q.back() << endl;
	
	cout << "map" << endl;
	map<int,int> m;
	cout << m[1] << endl;
	
	
	return 0;
}

