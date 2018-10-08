/* 

Problem Description -- Codeforces - http://codeforces.com/problemset/problem/20/C

You are given a weighted undirected graph. The vertices are enumerated from 1 to n. 
Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2?=?n?=?105,?0?=?m?=?105), 
where n is the number of vertices and m is the number of edges. 
Following m lines contain one edge each in form ai, bi and wi (1?=?ai,?bi?=?n,?1?=?wi?=?106), 
where ai,?bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. 
If there are many solutions, print any of them.

*/

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector < pii > vii;
typedef vector < pii >::iterator vpi;
typedef set< pii >::iterator spi;

typedef long long int64;
int64 D[100001];
int P[100001];
set<pair<int, int64> > Q;
vii G[100001];
stack<int> s;
	
	void dijikstra(int source, int N) {
		Q.insert(make_pair(0,source));
		for (int i = 1; i <= N; i++)
			D[i] = 1e18;
		P[source] = 1;
		D[source] = 0;
		
		while (!Q.empty()) {	
		    pair<int,int> top=*(Q.begin());
			Q.erase(Q.begin());
		    int u = top.second;
			if (D[u] < top.first)
				continue;
			vector< pair<int,int> >::iterator it;
			for (it=G[u].begin(); it!=G[u].end(); it++){
				int v = (*it).first;
				int w = (*it).second;
				
				if (D[v] > D[u]+w) {
					D[v] = D[u]+w;
					P[v] = u;
					Q.insert(make_pair(D[v],v));
				}
			}
		}
		if (P[N] == 0) {
			cout << -1;
			return;
		}
		
		int v = N;
		s.push(v);
		while (v != 1) {
			int t = P[v];
			v = t;
			s.push(t);
		}
		    
		while (!s.empty()) {
			
			cout << s.top() << " ";
			s.pop();
		}
		return;
	}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int V, E, v1, v2, w;
	cin >> V >> E;
	while (E--) {
		cin >> v1 >> v2 >> w;
		G[v1].push_back(make_pair(v2,w));
		G[v2].push_back(make_pair(v1,w));
	}
	
	dijikstra(1, V);	
	return 0;
}


