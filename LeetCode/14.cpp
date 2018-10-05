class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        if (sz == 0)
            return "";
        
        sort(strs.begin(), strs.end());
        
        string str1 = strs[0];
        string str2 = strs[sz-1];
        
        int sz1 = str1.length();
        int sz2 = str2.length();
        
        int mn = (sz1 < sz2) ? sz1 : sz2;
        
        if (mn == 0)
            return "";
        
        int i = 0;
        string s = "";
        
        while (i < mn) {
            if (str1[i] == str2[i])
                s += str1[i];
            else 
                break;
            i++;
        } 
        
        return s;
    }
};


/*

Sort and check the first and last string in the sorted array. IF they have something in common, the other strings are bound to have the same common thing.
Since, after sorting it becomes a dictionary.


*/
