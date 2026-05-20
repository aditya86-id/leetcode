class Solution {
public:
    vector<int> res;
    bool twoSum(vector<int> &arr, int target){
        unordered_set<int> s;

        for(int i = 0; i < arr.size(); i++){
            int complement = target - arr[i];

            if(s.find(complement) != s.end())
                return true;

            s.insert(arr[i]);
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        res.clear();                
        if(root == NULL) return false;

        queue<TreeNode*> q;
        q.push(root);

        // BFS traversal to collect values
        while(!q.empty()){
            auto ele = q.front();
            q.pop();

            res.push_back(ele->val);

            if(ele->left) q.push(ele->left);
            if(ele->right) q.push(ele->right);
        }

        return twoSum(res, k);
    }
};