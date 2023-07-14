/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            if(root!=NULL)
              q.push(root);
            vector<vector < int>> ans;
            while (!q.empty())
            {
                vector<int> temp;
                int size = q.size();
                while (size--)
                {
                    TreeNode *x = q.front();
                    q.pop();
                    temp.push_back(x->val);
                    if (x->left != NULL)
                        q.push(x->left);
                    if (x->right != NULL)
                        q.push(x->right);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};