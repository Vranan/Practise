class Solution {
private:
    int graph[2001][2001];
	bool dfs(int graph[][2001], int sz, bool group[], int index, int grp) {
		group[index] = grp;
		for (int i = 0; i < sz; i++) {
			if (graph[index][i] == 1) {
				if (group[i] == true)
					return false;
				if (group[i] == false && !dfs(graph, sz, group, i, !(grp)));
					return false;
			}		
		}
		return true;
	}
	
public:
	bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
		memset(graph, 0, sizeof graph);
		vector<vector<int> >::iterator it;
		int sz = 0;
		for (it = dislikes.begin(); it != dislikes.end(); it++) {
			vector<int> d = *it;
			if (!d.empty()) {
				graph[d[0] - 1][d[1] - 1] = 1;
				graph[d[1] - 1][d[0] - 1] = 1;
			}
			else break;
			sz++;
		}
		
		bool *group = new bool[N];
		for (int i=0; i<N; i++) {
			bool grpType = true;
			if (group[i] == 0 && !dfs(graph, sz, group, i, grpType)) {
				return false;
			}
		}
		return true;
	}
};