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
    int m=0;
    int diameter(TreeNode* root)
    {
        if(!root)return 0;
        int left=diameter(root->left);
        int right=diameter(root->right);
         m=max(m,left+right);
        return max(left,right)+1;
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=diameter(root);
        return m;
    }
};