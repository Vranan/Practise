/*

MICEMAZE - Mice and Maze
#shortest-path #bfs #dijkstra-s-algorithm
A set of laboratory mice is being trained to escape a maze. 
The maze is made up of cells, and each cell is connected to some other cells. 
However, there are obstacles in the passage between cells and therefore 
there is a time penalty to overcome the passage Also, some passages 
allow mice to go one-way, but not the other way round.

Suppose that all mice are now trained and, when placed in an arbitrary cell in the maze, 
take a path that leads them to the exit cell in minimum time.
We are going to conduct the following experiment: a mouse is placed 
in each cell of the maze and a count-down timer is started. When the timer 
stops we count the number of mice out of the maze.

Problem
Write a program that, given a description of the maze and the time limit, 
predicts the number of mice that will exit the maze. Assume that there are 
no bottlenecks is the maze, i.e. that all cells have room for an arbitrary number of mice.

Input
The maze cells are numbered $1, 2, \ldots, N$, where $N$ is the total number of cells.
You can assume that $N \le 100$.
The first three input lines contain $N$, the number of cells in the maze, $E$, 
the number of the exit cell, and the starting value $T$ for the count-down timer (in some arbitrary time unit).
The fourth line contains the number $M$ of connections in the maze, 
and is followed by $M$ lines, each specifying a connection with three integer numbers: 
two cell numbers $a$ and $b$ (in the range $1, \ldots, N$) and the number of time units it takes to travel from $a$ to $b$.
Notice that each connection is one-way, i.e., the mice can't travel from $b$ to $a$ 
unless there is another line specifying that passage. Notice also that the time required to travel in each direction might be different.

Output
The output consists of a single line with the number of mice that reached the exit cell $E$ in at most $T$ time units.

Example
Input:
4 
2 
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;


void djikstra(vector<pair<int,int> > maze[], int ncells, int dest, int t_val) {
	int count = 0;
	for (int i = 1; i <= ncells; i++) {
		int dist[10001];
		dist[i] = 0;
		set<pair<int,int> > myset;
		myset.insert(make_pair(0, i));
		while(!myset.empty()) {
			cout << "Apple" << endl;
			set<pair<int,int> >::iterator si = myset.begin();
			int u = (*si).second;
			myset.erase(si);
			vector< pair<int, int> >::iterator it;
			for (it = maze[u].begin(); it != maze[u].end(); it++) {
				cout << "Cider" << endl;
				int v = (*it).first;
				int t = (*it).second;
				if (dist[v] > dist[u]+t) {
					dist[v] = dist[u]+t;
					myset.insert(make_pair(dist[v],v));
				}
			}
		}
		cout << "Source = " << i << endl;
		if (dist[dest] <= t_val) 
		 	count++;
	}
	cout << count;
    
}

/* 
	void bfs(vector<pair<int,int> > maze[], int t_val, int dest) {
	queue<int> myq;
	myq.push(1);
	while(!myq.empty()) {
		int top = myq.front();
		myq.pop();
		if (djikstra(maze, top, dest) == t_val) 
			nescm = nescm + 1; 
		vector<pair<int,int> >::iterator it;
		for (it = maze[top].begin(); it != maze[top].end(); it++) {
			myq.push((*it).second);
		}
	}
} */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ncells, necell, strt_val_timer,maze_conn, u, v, t;
	cin >> ncells >> necell >> strt_val_timer >> maze_conn;
	vector <pair<int,int> > maze[100001];
	while(maze_conn--){
		cin >> u >> v >> t;
		maze[u].push_back(make_pair(v, t));
	}
	
	djikstra(maze, ncells, necell, strt_val_timer);
	return 0;
}

























