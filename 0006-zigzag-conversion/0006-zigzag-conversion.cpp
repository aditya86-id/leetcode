class Solution {
public:
    string convert(string s, int numsRows) {
        if(numsRows==1||numsRows>=s.length()){return s;}


        int idx=0,d=1;

        vector<vector<char>>rows(numsRows);


        for(char c:s){
            rows[idx].push_back(c);
            if(idx==0){
                d=1;
            }else if(idx==numsRows-1){
                d=-1;
            }
            
                idx+=d;
            }



            string result;
            for(auto& row:rows){
                for(char c:row){
                    result+=c;
                }
            }
        return result;
    }
};