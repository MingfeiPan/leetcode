/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode dummy = new TreeNode(-1);
        dummy.right = root;
        List<TreeNode> list = new ArrayList<>();
        if (root.right != null) {
            list.add(root.right);
        }
        if (root.left != null) {
            list.add(root.left);
        }
        while (list.size() > 0) {
            TreeNode cur = list.remove(list.size()-1);
            root.left = null;
            root.right = cur;
            root = root.right;
            if (cur.right != null) {
                list.add(cur.right);
            }
            if (cur.left != null) {
                list.add(cur.left);
            }
        }
        root = dummy.right;
    }
}
