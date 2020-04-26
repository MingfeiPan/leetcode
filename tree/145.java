/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        List<TreeNode> stack = new ArrayList<>();
        while (true) {
            if (root != null) {
                ret.add(0, root.val);
                if (root.left != null) {
                    stack.add(root.left);
                }
                if (root.right != null) {
                    stack.add(root.right);
                }
            }
            if (stack.size() == 0) {
                break;
            }
            root = stack.remove(stack.size()-1);
        }
        return ret;
    }
}
