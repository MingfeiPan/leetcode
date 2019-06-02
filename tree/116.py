"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return None
        
        dummy = root
        while dummy.left: #dummy 负责遍历到每层的最左
            cur = dummy
            while cur: #cur 负责遍历每层
                cur.left.next = cur.right #链接cur的left->right
                if cur.next:
                    cur.right.next = cur.next.left #如果cur有next 则在此层连接下一层的间隙节点, 也就是 cur.right.next -> cur.next-left
                cur = cur.next
            dummy = dummy.left
            
        return root
                
                
                
                
            
                
                
