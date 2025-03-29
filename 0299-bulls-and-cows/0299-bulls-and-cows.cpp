class Solution {
public:
    string getHint(string secret, string guess) {
    int x=0;
    int n=secret.size();
    unordered_map<char,int>f1;
    unordered_map<char,int>f2;    
    for(int i=0;i<n;++i){
        if(secret[i]==guess[i]){
            x++;
        }

        else{
            f1[secret[i]]++;
            f2[guess[i]]++;
        }

    }
    int y=0;
    for(auto it:f2){
        if(f1[it.first]!=0 && it.second!=0){
            y+=min(f1[it.first],it.second);
        }
    }
    string ans = to_string(x)+'A'+to_string(y)+'B';

    return ans;
    }
};