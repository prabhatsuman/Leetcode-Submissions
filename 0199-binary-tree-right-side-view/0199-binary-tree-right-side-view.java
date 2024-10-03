import java.util.*;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            TreeNode rightmostNode = null;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode currentNode = queue.poll();
                rightmostNode = currentNode;
                
               
                if (currentNode.left != null) {
                    queue.offer(currentNode.left);
                }
                if (currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }
           
            ans.add(rightmostNode.val);
        }
        
        return ans;
    }
}
