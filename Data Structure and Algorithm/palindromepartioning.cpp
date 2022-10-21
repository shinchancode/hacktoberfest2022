// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subS;
        solve(0,s,res,subS);
        return res;
    }
    
    void solve(int index, string s, vector<vector<string>> &res, vector<string> &subS) {
        //Base case - reaching end of the string
        if(index == s.size()) {
            res.push_back(subS);
            return;
        }
        
        for(int i=index;i<s.size();i++) {
            if(isPal(s,index,i)) {  
                subS.push_back(s.substr(index, i-index+1)); //pushing substring till partition if palindrome
                solve(i+1,s,res,subS);
                subS.pop_back();
            }
        }
    }
    
    bool isPal(string str, int start , int end) {
        while(start <= end) {
            if(str[start++] != str[end--])
                return false;
        }
        return true;
    }
};
