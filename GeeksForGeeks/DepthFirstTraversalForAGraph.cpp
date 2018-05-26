#include <iostream>
#include <vector>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[]) {
	vis[s] = true;
	cout << s << "";
	for (vector<int>::iterator i = g[top].begin(); i != g[top].end(); i++) {
		if (!vis[*i]) {
			dfs(*i,g,vis);
		}
	}	
}
	