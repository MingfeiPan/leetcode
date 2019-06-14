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
    
