#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
        int factorial = 1;
        for(int i = 1; i <=n; ++i){
          factorial *= i;
        }
        return factorial;
    }
    
int numTrees(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
        int k = fact(2*n);
        int l = fact(n);
        int m = fact(n+1);
        
        return (int(k/(l*m)));
        
}

int main() {

	return 0;
}

