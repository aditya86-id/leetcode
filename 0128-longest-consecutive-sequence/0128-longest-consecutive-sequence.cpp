class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int count = 0;
        int element = 0;
        int res = 0;
        int n = arr.size();
        unordered_set<int> temporary(arr.begin(),arr.end());
        for(int i:temporary){
            element = i;
            count = 1;
            if(temporary.find(element-1) == temporary.end()){
                element+=1;
                while(temporary.find(element) != temporary.end()){
                    count++;
                    element+=1;
                }        
                res = max(res, count);
            }
        }
        return res;
    }
};