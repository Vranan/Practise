#include <iostream>
#include <vector>
using namespace std;

class graph {
	
	private:
		int N;
		vector<int> conArr;
		vector<int> depArr;
	
	public:
		
		graph(int n, vector<int> d) {
			N = n;
			vector<int> connArr(N);
			conArr = connArr;
			depArr = d;
			for (int i = 0; i < N; i++) {
				conArr[i] = i;
			}
		}
	
		int root(int p) {
			while (conArr[p] != p) {
				p = conArr[p];
			}
			return p;
		}
			
		void connect(int p, int q) {
			int pid = root(p);
			int qid = root(q);
			if (pid == qid) {
				return;
			}
			else { 
				conArr[q] = pid;
			}			
		}
		
		void calc() {
		    for (int i = 0; i < N; i++) {
				if (depArr[i]) {
					connect(i,depArr[i]);
				}
			}
			
			for (int  i = 0; i < N; i++) {
				cout << "i = " << i << " -- " << conArr[i] << " = " << "conArr[" << i << "]" << endl;
			}
		}
		
		
};





int main() {
	
	int N, D, d1, d2;
	cin >> N >> D;
	vector<int> depArr(D);
	vector<int> conArr(N);
	
	while (D--) {
		cin >> d1 >> d2;
		depArr[d1] = d2;
	}
	
	graph gp(N,depArr);
	cout << "Calling the calc function from the graph class" << endl;
	gp.calc();
	

}