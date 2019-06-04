# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return 
        # pre-order traversal
        l = []
        l.append(root)
        while l:
            cur = l.pop()
            if cur.right:
                l.append(cur.right)
            if cur.left:
                l.append(cur.left)
            if l:
                cur.right = l[-1] #如果left 存在则指向left 否则指向right
            cur.left = None
