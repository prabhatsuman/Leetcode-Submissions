/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);

        auto dfs = [&](auto& dfs, TreeNode* root) -> TreeNode* {
            if (root->val > large) {
                return dfs(dfs, root->left);
            } else if (root->val < small) {
                return dfs(dfs, root->right);
            }
            return root;
        };
        return dfs(dfs, root);
    }
};
