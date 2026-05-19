class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* rightnode = nullptr;
            int size = q.size();

            for (int i = size; i > 0; i--) {
                Node* ele = q.front();
                q.pop();

                // connect next pointer
                ele->next = rightnode;
                rightnode = ele;

                // push children (RIGHT → LEFT)
                if (ele->right)
                    q.push(ele->right);
                if (ele->left)
                    q.push(ele->left);
            }
        }
        return root;
    }
};