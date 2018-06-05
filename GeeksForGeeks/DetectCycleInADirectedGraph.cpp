#include<bits/stdc++.h>
using namespace std;

class Graph {
		int V;
		list<int> *adj;
	public :
		Graph(int V);
		void addEdge(int v, int w);
		bool isCyclic();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

int Graph::size() {
	return adj[0].size();
}

void Graph::addEdge(int v,int w) {
    adj[v].push_back(w);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
		
        int _size, N;
        cin >> _size >> N;
        Graph *g = new Graph(_size);
		
        for(int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g->addEdge(u, v);
        }		
        cout<<g->isCyclic()<<endl;
    }
}

bool Graph::isCyclic() {
    bool *vis = new bool[V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			vis[j] = false;
			
		stack<int> st;
		st.push(i);
		vis[i] = true;
		while(!st.empty()) {
			int top = st.top();
			cout << "top = " << top << endl;
			st.pop();
		
			for (list<int>::iterator it = adj[top].begin(); it != adj[top].end(); it++) {
				cout << "i = " << i << "*it = " << *it << endl;
				if (*it == i) {
					cout << "*it = " << *it << "= i = " << i << ", return true" << endl;
					return true;
				}
				else if (!vis[*it]){
					cout << "vis[" *it << "] = " << vis[*it] << "st.push(" << *it << ")" << endl;
					vis[*it] = true;
					st.push(*it);
				}
				
			}
		}
	}
	cout << "return false" << endl;
	return false;
}
















