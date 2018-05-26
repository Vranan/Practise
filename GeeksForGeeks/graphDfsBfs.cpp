#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
		}
		
		void init() {
			for (int i = 0; i < nodes; i++) {
				vis[i] = false;
			}
		}

		void addEdge(int n1, int n2) {
			g[n1].push_back(n2);
		}

		void dfs(int s) {
			init();
			stack<int> st;
			st.push(s);
			while (!st.empty()) {
				int t = st.top();
				st.pop();
				if (vis[t]) continue;
				vis[t] = true;
				cout << t << " ";
				for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); it++) {
					if (!vis[*it]) {
						st.push(*it);
					}
				}
			}
		}
		
		void bfs(int s) {
			init();
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int f = q.front();
				q.pop();
				if (vis[f]) continue;
				vis[f] = true;
				cout << f << " ";
				for (vector<int>::iterator it = g[f].begin(); it != g[f].end(); it++) {
					if (!vis[*it]) {
						q.push(*it);	
					}
				}
			}
}
};

int main() {
	
	int N;
	cout << "Enter the Number of Nodes" << endl;
	cin >> N;
	cout << "The number of Nodes are = " << N << endl;
	graph g(N);
	g.addEdge(0, 1);
	g.addEdge(0, 6);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 6);
	g.addEdge(6, 0);
	cout << "Depth First Search" << endl;
	g.dfs(2);
	cout << endl << "Breadth First Search" << endl;
	g.bfs(2);
	return 0;
}



