#include <iostream>
#include <stack>
#include <list>

using namespace std;
class topologicalSortGraph {
	
	private:
		list<int> *adj;
		int N;
	
	public:
		topologicalSortGraph(int n) {
			adj = new list<int>[n];
			N = n;
		}
	
		void topologicalSort() {
			bool *vis = new bool[N];
			for (int i = 0; i < N; i++) {
				vis[i] = false;
			}
			stack<int> st;
			for (int i = 0; i < N; i++) {
				if (!vis[i]) {
					vis[i] = true;
					st.push(i);
				
					while (!st.empty()) {
						int t = st.top();
						st.pop();
						cout << t << endl;
						list<int>::iterator it;
						for (it = adj[t].begin(); it != adj[t].end(); it++) {
							if (!vis[*it]) {
								vis[*it] = true;
								st.push(*it);
							}
						}
					
					}
				}
				else continue;
			}

		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
		}
};
int main() {
	
	topologicalSortGraph tsg(6);
	tsg.addEdge(5, 0);
	tsg.addEdge(5, 2);
	tsg.addEdge(4, 0);
	tsg.addEdge(3, 1);
	tsg.addEdge(2, 3);
	tsg.addEdge(1, 4);
	tsg.topologicalSort();

return 0;
}