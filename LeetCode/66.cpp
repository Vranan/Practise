class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size()-1;
        vector<int> vec;
        int carry = 1;
        stack<int> q;
        for (int i = sz; i >= 0; i--) {
            int dig = (digits[i] + carry) % 10;
            q.push(dig);
            carry = (digits[i] + carry)/10;
            
            
        }
        
        if (carry == 1)
            q.push(1);
        
        while (!q.empty()){
            vec.push_back(q.top());
            q.pop();
        }
            
        return vec;
        
        
    }
};
