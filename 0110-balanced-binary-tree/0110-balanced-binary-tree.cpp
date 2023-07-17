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
    int flag=true;
    int height(TreeNode* root)
    {
        if(root==NULL)return 0;
        int right=height(root->right);
        int left=height(root->left);
        if(abs(right-left)>1)
        {
            flag=false;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ans=height(root);
        return flag;
    }
};