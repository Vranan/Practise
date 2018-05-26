//#include <bits/stdc++.h>
//typedef vector< vector<int> > vector2d;

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class graph {
	
	private:
		int nodes;
		vector<int> *g;
		bool *vis;

	public:

		graph(int n) {
			this->nodes = n;
			g = new vector<int>[n];
			vis = new bool[n];
			for (int i = 0; i < n; i++) {
				vis[i] = false;
			}
			// cout << "g and vis are initialized" << endl;
		}

		void addEdge(int n1, int n2) {
		    // cout << "Edge is added between " << n1 << " and " << n2 << endl;
			g[n1].push_back(n2);
		}

		void dfs(int s) {
			stack<int> st;
			st.push(s);
			while (!st.empty()) {
				int t = st.top();
				vis[t] = true;
				st.pop();
				cout << t << " ";
				for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); it++) {
					if (!vis[*it]) {
						st.push(*it);
					}
				}
			}
		}
};

int main() {
	
	int N;
	// cout << "Enter the Number of Nodes" << endl;
	cin >> N;
	// cout << "The number of Nodes are = " << N << endl;
	graph g(N);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 4);
	g.addEdge(3, 1);
	g.dfs(1);
	return 0;
}
