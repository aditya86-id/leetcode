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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return solve(root,dp);

        
    }

    private:
    int solve(TreeNode*node,unordered_map<TreeNode*,int>&dp){
        if(!node){return 0;}
        int pick = node->val;
        if(dp.find(node)!=dp.end()){return dp[node];}
        if(node->left && node->left->left){pick+=solve(node->left->left,dp);}
        if(node->left && node->left->right){pick+=solve(node->left->right,dp);}
        if(node->right && node->right->left){pick+=solve(node->right->left,dp);}
        if(node->right && node->right->right){pick+=solve(node->right->right,dp);}
        int not_pick = 0;
        if(node->left){not_pick+=solve(node->left,dp);}
        if(node->right){not_pick+=solve(node->right,dp);}
        return dp[node] = max(pick,not_pick);
        

    }
};