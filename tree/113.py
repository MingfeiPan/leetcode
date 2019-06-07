# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ret = []
        self.dfs(root, sum, [], ret)
        return ret
    
    def dfs(self, root, left, cur, ret):
        if not root:
            return 
        if not root.left and not root.right:
            if root.val == left:
                ret.append(cur+[root.val])
        else:
            self.dfs(root.left, left - root.val, cur[:] + [root.val], ret) 
            self.dfs(root.right, left - root.val, cur[:] + [root.val], ret) 
    
