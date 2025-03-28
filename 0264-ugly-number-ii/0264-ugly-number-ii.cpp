class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq; 
        unordered_set<int> vis;

        pq.push(1);
        vis.insert(1);
        vector<int> factors = {2,3,5};

        long curr_ugly = 1;
        for(int i = 0; i < n; i++){
            curr_ugly = pq.top();
            pq.pop();

            for(int f: factors){
                long next_ugly = curr_ugly * f;
                if(vis.find(next_ugly) == vis.end()){
                    pq.push(next_ugly);
                    vis.insert(next_ugly);
                }
            }
        }

        return (int)curr_ugly;
    }
};