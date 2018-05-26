void bfs(int s, vector<int> g, bool vis[]) {
	queue<int> q;
	vis[s] = true;
	q.push(s);
	cout  << s << " "; 
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (vector<int>::iterator it = g[front].begin(); it != g[front].end(); it++) {
			if (!vis[*it]) {
				vis[*it] = true;
				cout << *it << " ";
				q.push(*it);	
			}
		}
	}
}