#include<bits/stdc++.h>
using namespace std;

void itr(vector<int> vec) {

    for(auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int countPrimes(int n) {


        if (n <= 1)
            return 0;
        
        int count = 0;
        bool flag[n] = {0};
        int n2 = sqrt(n);
    
        for (int i = 2; i <= n2; i++) {
            
            if (flag[i] == false) {
                for (int j = i*i; j < n; j = j+i)
                    flag[j] = true;  
            }
            
        }
      
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0)
                count++;
        }
       
       return count-2;

       
}

int main() {

    int cp = countPrimes(10);
    cout << "\ncp = " << cp << endl;
    
    return 0;
}
