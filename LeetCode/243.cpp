#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        
        int sz = words.size();
        
        if (sz == 0)
            return 0;
        
        int diff = INT_MAX;
        int d1 = INT_MAX;
        int d2 = INT_MAX;
        
        for (int i = 0; i < sz; i++) {
            
            
            if (words[i] == word1) {
                d1 = i;
            } else if (words[i] == word2) {
                d2 = i;
            }
            
            diff = (d1 != INT_MAX && d2 != INT_MAX) ? min(diff, abs(d1-d2)) : INT_MAX;
        }
        
        return (diff == INT_MAX ? -1 : diff);
        
    }
};

int main() {

	return 0;
}

