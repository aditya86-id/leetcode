class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n = q.size();
            vector<int> l;
            vector<int> r;

            for(int i=0;i<n;i++)
            {
                auto ele = q.front();
                q.pop();

             
                if(ele->left!=nullptr){
                    q.push(ele->left);
                    l.push_back(ele->left->val);
                } else {
                    l.push_back(INT_MIN); 
                }

                if(ele->right!=nullptr){
                    q.push(ele->right);
                    r.push_back(ele->right->val);
                } else {
                    r.push_back(INT_MIN); 
                }
            }

            int i=0, j=r.size()-1;
            while(i<l.size()){
                if(l[i] != r[j]) return false;
                i++; j--;
            }
        }
        return true;
    }
};