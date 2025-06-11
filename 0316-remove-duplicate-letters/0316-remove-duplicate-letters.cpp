class Solution {
public:
    string removeDuplicateLetters(string s) {
    
       unordered_map<char,int>mp;
       for(int i=0;i<s.length();i++){
        mp[s[i]] = i;
       } 
       stack<char>st;
       unordered_set<char>vis;

       for(int i=0;i<s.length();i++){
        if(vis.find(s[i])!=vis.end()){continue;}


        while(!st.empty()&&s[i]<st.top()&&i<mp[st.top()]){
            vis.erase(st.top());
            st.pop();
        }
        vis.insert(s[i]);
        st.push(s[i]);
       }

       string result;
       while(!st.empty()){
        result = st.top()+result;
        st.pop();
       }

       return result;
    }
};