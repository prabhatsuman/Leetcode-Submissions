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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        function<void(TreeNode*)> helper=[&](TreeNode* root)
        {
            if(root==NULL)return;
            helper(root->left);
            count++;
            if(count==k)
            {
                ans=root->val;
            }
            helper(root->right);
        };
        helper(root);
        return ans;
    }
};