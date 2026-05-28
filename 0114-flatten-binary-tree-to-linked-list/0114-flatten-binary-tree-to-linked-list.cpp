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
    vector<TreeNode*>result;
    void flatten(TreeNode* root) {

       if(root==NULL) return;

    //    if(root->val==0) return 0;

       flatten(root->left);
       flatten(root->right);

        TreeNode* leftroot = root->left;
        TreeNode* rightroot = root->right;

        root->left = NULL;
        root->right = leftroot;

        while(root->right!=NULL){

            root = root->right;
        }

        root->right=rightroot;
    }
};