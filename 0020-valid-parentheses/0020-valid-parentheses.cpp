class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> map={{')', '('}, {']', '['}, {'}', '{'}};
        for(char c:s){
            if(!st.empty()){
                char i=st.top();
                if(map[c]==i){
                    st.pop();
                    continue;
                }
            } 
            st.push(c);
        }
        return st.empty();
    }
};