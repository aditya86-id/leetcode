class Solution {
public:
bool vCheck(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}


    int maxFreqSum(string s) {
    int n=s.size();
    unordered_map<char,int>mp;
     for(char i:s){
        mp[i]++;    
     }   
     int vcount = 0;int ccount = 0;

     for(auto i:mp){
        char c=i.first;int count = i.second;
        if(vCheck(c)){
            vcount = max(vcount,mp[c]);
        }
        else{
            ccount = max(ccount,mp[c]);
        }
     }
     return vcount+ccount;
    }
};