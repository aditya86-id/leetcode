class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    unordered_map<int,int>mp;
    int n=x.size();
    for(int i=0;i<n;++i){
        mp[x[i]]=max(mp[x[i]],y[i]);

    } 
    priority_queue<int>pq;
    for(auto &[key,val]:mp){
        pq.push(val);

    }
      if(pq.size()<3) return -1;

      int sum = 0;
      for(int i=0;i<3;i++){
        sum+=pq.top();
        pq.pop();
      }

      return sum;

    }
};