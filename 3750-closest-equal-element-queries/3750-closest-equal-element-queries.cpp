class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    unordered_map<int, int> leftSeen, rightSeen;
    vector<int> dist(nums.size(), INT_MAX), ans;
    for(int i = 0; i < nums.size()*2; ++i){
        if(leftSeen.find(nums[i % nums.size()]) != leftSeen.end()){
            dist[i % nums.size()] = i - leftSeen[nums[i % nums.size()]];
        }
        leftSeen[nums[i % nums.size()]] = i;
    }
    for(int i = nums.size() * 2 - 1; i >= 0; --i){
        if(rightSeen.find(nums[i % nums.size()]) != rightSeen.end()){
            dist[i % nums.size()] = min(dist[i%nums.size()], (rightSeen[nums[i % nums.size()]] - i));
        }
        rightSeen[nums[i % nums.size()]] = i;
    }
    for(auto q: queries){
        if(dist[q] >= nums.size()) ans.push_back(-1);
        else ans.push_back(dist[q]);
    }
    return ans;

    }
};
