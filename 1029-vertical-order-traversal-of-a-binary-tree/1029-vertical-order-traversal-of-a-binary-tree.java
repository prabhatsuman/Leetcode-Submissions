/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Tuple{
    TreeNode x;
    int row;
    int col;
    public Tuple(TreeNode x,int row,int col)
    {
        this.x=x;
        this.row=row;
        this.col=col;
    }
};
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        TreeMap<Integer,TreeMap<Integer,PriorityQueue<Integer>>> mp=new TreeMap<>();
        Queue<Tuple> q= new LinkedList<>();

        q.offer(new Tuple(root,0,0));

        while(!q.isEmpty())
        {
            Tuple temp=q.poll();
            TreeNode node=temp.x;
            int x_row=temp.row;
            int y_col=temp.col;

            mp.putIfAbsent(x_row,new TreeMap<>());
            mp.get(x_row).putIfAbsent(y_col,new PriorityQueue<>());
            mp.get(x_row).get(y_col).offer(node.val);

            if(node.left!=null)
            {
                q.offer(new Tuple(node.left,x_row-1,y_col+1));
            }
            if(node.right!=null)
            {
                q.offer(new Tuple(node.right,x_row+1,y_col+1));
            }
        }

        for(TreeMap<Integer,PriorityQueue<Integer>> col: mp.values())
        {
            List<Integer> column=new ArrayList<>();
            for(PriorityQueue<Integer> nodes : col.values())
            {
                while(!nodes.isEmpty())
                {
                    column.add(nodes.poll());
                }
            }
            ans.add(column);
        }
        return ans;
    }
}