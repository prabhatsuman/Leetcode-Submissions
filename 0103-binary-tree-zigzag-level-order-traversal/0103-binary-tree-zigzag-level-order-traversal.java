import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;  

        Queue<TreeNode> q = new LinkedList<>();
        boolean flag = true;  
        q.offer(root);
        
        while (!q.isEmpty()) {  
            int size = q.size();
            List<Integer> temp = new ArrayList<>();
            
            for (int i = 0; i < size; i++) {
                TreeNode x = q.poll();
                temp.add(x.val);
                
                if (x.left != null) {
                    q.offer(x.left);
                }
                if (x.right != null) {
                    q.offer(x.right);
                }
            }
            
            if (!flag) {
                Collections.reverse(temp);  
            }
            
            ans.add(temp);
            flag = !flag;
        }
        
        return ans;
    }
}
