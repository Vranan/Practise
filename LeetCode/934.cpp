class Solution {
    
private: 
int paint(vector<vector<int>>& A, int i, int j, int cl) {
        
    if (i < 0 || j < 0 || i == A.size() || j == A[0].size() || A[i][j] != 1) return false;
    A[i][j] = cl;
    return 1 + paint(A, i+1, j, cl) + paint(A, i-1, j, cl) + paint(A, i, j+1, cl) + paint(A, i, j-1, cl);
}
    
bool exp(vector<vector<int>>& A, int i, int j, int cl) {
    if (i < 0 || j < 0 || i == A.size() || j == A[0].size()) return false;
    if (A[i][j] == 0) A[i][j] = cl+1;
    return A[i][j] == 2;
}
    
public:

    int shortestBridge(vector<vector<int>>& A) {
        
        for (auto i = 0, cl = 2; i < A.size(); i++) {
            for (auto j = 0; j < A[0].size(); j++) {
                if (paint(A, i, j, cl)) cl++;
            }
        }
        
for (auto cl = 3; ;cl++) {
    for (auto i = 0; i < A.size(); i++) {
        for (auto j = 0; j < A[0].size(); j++) {
                    
        if (A[i][j] == cl) {
            if (exp(A, i-1, j, cl) || exp(A, i+1, j, cl) || exp(A, i, j+1, cl) || exp(A, i, j-1, cl)) 
                return cl-3;            
        }
        }
    }        
}
    }
};
