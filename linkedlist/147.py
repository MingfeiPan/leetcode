# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#不新建任何node, 完全复用原始节点
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        cur = head.next #遍历链表的游标, 从第二个开始
        head.next = None #头节点作为新的起点
        while cur:
            dummy = head #重置dummy到头节点
            if cur.val <= dummy.val: #处理插入节点在头节点之前的情况
                temp = cur
                cur = cur.next
                temp.next = dummy
                head = temp
            else:
                while dummy.next and cur.val > dummy.next.val:
                    dummy = dummy.next
                if dummy.next is None: #处理cur是当前最大节点的情况
                    temp = cur
                    cur = cur.next
                    dummy.next = temp
                    temp.next = None
                else:                  #将cur插入dummy, dummy.next之间
                    temp = cur
                    cur = cur.next
                    temp.next = dummy.next
                    dummy.next = temp
                    
        return head
                
            
            
