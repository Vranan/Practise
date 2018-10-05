#include<bits/stdc++.h>
using namespace std;

bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;
        
        for (int i = 0; i < deck.size(); i++) {
            m[deck[i]] = m[deck[i]] + 1;
            cout << "m[" << deck[i] << "] = " << m[deck[i]] << endl;
        }
        
        int v = m.begin()->second;
        
        for (auto& i : m) {
            if (i.second != v)
                return false;
            else
                v = i.second;
        }
        
        return true;
        
}

int gcd(int a,int b)
{
    while(1)
    {
        int c = a%b;
        if(c==0)
          return abs(b);
        a = b;
        b = c;
    }
}

int main() {
	vector<int> m{1,1,1,2,2,2,3,3};
	bool a = hasGroupsSizeX(m);
	int b = gcd(4,6);
	cout << "b = " << b << endl;
	
	return 0;
}
