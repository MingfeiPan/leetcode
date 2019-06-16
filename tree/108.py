# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


#recursive solution
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        
        if not nums:
            return None
        pivot = len(nums) // 2
        
        root = TreeNode(nums[pivot])
        root.left = self.sortedArrayToBST(nums[:pivot])
        root.right = self.sortedArrayToBST(nums[pivot+1:])
        
        return root
    

#non-ercursive solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        
        if not nums:
            return None
        
        pivot = (len(nums)-1) // 2 
        
        l = []
        root = TreeNode(nums[pivot])
        l.append([root, 0, pivot-1])
        l.append([root, pivot+1, len(nums)-1])
        
        while l:
            cur, left, right = l.pop()
            
            if left <= right:
                pivot = left + (right - left) // 2 #注意与(right - left) // 2的区别 
                node = TreeNode(nums[pivot])
                if nums[pivot] <= cur.val:
                    cur.left = node
                else:
                    cur.right = node
                    
                l.append([node, left, pivot-1])
                l.append([node, pivot+1, right])
            
        return root
