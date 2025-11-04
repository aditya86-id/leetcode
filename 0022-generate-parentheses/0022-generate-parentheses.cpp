class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str; 
        backtrack(n, str, result, 0, 0);
        return result;
    }

    void backtrack(int n, string &str, vector<string>& result, int open, int close){
        if(str.size()==n*2){
            result.push_back(str);
            return;
        }

        if(open<n){
            str.push_back('(');
            backtrack(n, str, result, open+1, close);
            str.pop_back();
        }

        if(close<open){
            str.push_back(')');
            backtrack(n, str, result, open, close+1);
            str.pop_back();
        }
    }
};