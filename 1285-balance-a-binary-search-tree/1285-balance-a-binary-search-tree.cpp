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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderTraversal;
        function<void(TreeNode*)> inorder=[&](TreeNode* root)
        {
            if(!root)
            {
                return;
            }
            inorder(root->left);
            inorderTraversal.push_back(root->val);
            inorder(root->right);
        };
        inorder(root);
        function<TreeNode*(int,int)> bst=[&](int start,int end)->TreeNode*
        {
            if(start>end)
            {
                return NULL;
            }
            int mid=(start+end)/2;
            TreeNode* root=new TreeNode(inorderTraversal[mid]);
            root->left=bst(start,mid-1);
            root->right=bst(mid+1,end);
            return root;
        };
        TreeNode* ans=bst(0,inorderTraversal.size()-1);
        return ans;

    }
};