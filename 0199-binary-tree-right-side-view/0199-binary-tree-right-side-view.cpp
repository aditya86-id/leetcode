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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        int prev = -1;
        if(root==NULL) return{};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* ele = q.front();
            q.pop();
            if(ele == NULL){
    result.push_back(prev);
    if(!q.empty()) q.push(NULL);
    continue;
}

           if(ele->left!=NULL) q.push(ele->left);
           if(ele->right!=NULL) q.push(ele->right);

           prev = ele->val;
        }

        return result;
    }
};