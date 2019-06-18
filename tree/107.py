# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        ret = []
        l = [(root, 0)]

        while l:
            cur, level = l.pop()            
            if len(ret) == level:
                ret.append([cur.val])
            else:
                ret[level].insert(0, cur.val)
            if cur.left:
                l.append((cur.left, level+1))
            if cur.right:
                l.append((cur.right, level+1))

        
        ret.reverse()
        return ret
        
    
