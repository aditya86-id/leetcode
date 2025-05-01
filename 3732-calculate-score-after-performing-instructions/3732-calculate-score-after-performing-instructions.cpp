class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& values) {
        long long scr = 0;
        int i = 0;
        int n = ins.size();
        unordered_set<int>vis;

        while(i>=0 && i<n){
            if(vis.find(i)!=vis.end()){
                break;
                }
            vis.insert(i);
            if(ins[i] == "add"){
                scr+=values[i];
                i++;
            }
            else{
                int x = i + values[i];
                if (x < 0 || x >= n || vis.find(x) != vis.end()) {
                    break;


            }

            i=x;
            }
        }
       return scr;
    }
};