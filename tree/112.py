# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        
        return self.dfs(root, sum)
    
    def dfs(self, root, left):
        if not root:
            return False
        if not root.left and not root.right:
            if root.val == left:
                return True
            else:
                return False
        else:
            return self.dfs(root.left, left - root.val) or self.dfs(root.right, left - root.val)
    
