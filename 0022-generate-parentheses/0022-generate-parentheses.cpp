class Solution {
public:
    bool isvalid(string &s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push('(');
            else {
                if(!st.empty()) st.pop();
                 else return false;
                }
        }
        if(st.size()==0) return true;
        return false;
        
    }
    
   void solve(int n1,int n2,string s,vector<string> &ans){
        if(n1==0 && n2==0){
            if(isvalid(s)){
                ans.push_back(s);
            }
            return;
        }
        if(n1!=0) {s.push_back('(');  solve(n1-1,n2,s,ans); s.pop_back();}
       
        if(n2!=0) {s.push_back(')'); solve(n1,n2-1,s,ans);}
       
   
        
}

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        solve(n,n,"",ans);
        return ans;
        
    }
};