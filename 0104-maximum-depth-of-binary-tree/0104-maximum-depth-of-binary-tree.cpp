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
    int maxDepth(TreeNode* root) {
        int count=0;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return 0;
        }

        q.push(root);

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* ele=q.front();
                q.pop();
                if(ele->left!=NULL)
            {
                q.push(ele->left);
            }
            if(ele->right!=NULL)
            {
                q.push(ele->right);
            }
            }
            count++;
        }
        return count;
    }
};