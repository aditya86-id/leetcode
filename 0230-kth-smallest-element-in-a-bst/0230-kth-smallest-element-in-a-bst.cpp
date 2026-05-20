/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;

    int kthSmallest(TreeNode* root, int k) {
        res.clear();          

        if(root == NULL) return -1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto ele = q.front();
            q.pop();

            res.push_back(ele->val);

            if(ele->left) q.push(ele->left);
            if(ele->right) q.push(ele->right);
        }

        sort(res.begin(), res.end());

        return res[k-1];
    }
};