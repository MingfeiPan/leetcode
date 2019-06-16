# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        
        if not head:
            return None
        
        return self.foo(head, None)
    
    def foo(self, head, tail):
        if not head or head == tail:
            return None
        
        fast = slow = head
        
        while fast.next is not tail and fast.next.next is not tail: #快慢指针找到中点
            slow = slow.next
            fast = fast.next.next
            
        cur = TreeNode(slow.val)
        cur.left = self.foo(head, slow)
        cur.right = self.foo(slow.next, tail)
        return cur
        
    
