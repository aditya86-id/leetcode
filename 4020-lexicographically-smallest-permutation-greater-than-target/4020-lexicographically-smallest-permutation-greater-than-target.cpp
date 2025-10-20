class Solution {
public:
    string minStr(vector<int>freq){
        string res="";
        for(int i=0;i<26;i++)
            res.append(freq[i],'a'+i);
        return res;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26,0);
        for(char c:s) freq[c-'a']++;
        string ans = "",sb = "";
        for(int i=0;i<s.size();i++){
            int curr = target[i]-'a';
        for(int j=curr;j<26;j++){
            if(freq[j]==0) continue;
            freq[j]--;
            sb.push_back('a'+j);
            string temp = sb+minStr(freq);


            if(temp>target&&(ans.empty()||temp<ans))
                ans = temp;

            sb.pop_back();
            freq[j]++;
        }
        if(freq[curr]>0){
            freq[curr]--;
            sb.push_back('a'+curr);
        } else break;
        }


        return ans;
    }
};