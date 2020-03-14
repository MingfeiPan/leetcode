/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        int length = 0;
        ListNode cur = head;
        
        while (cur != null) {
            length++;
            cur = cur.next;
        }
        
        cur = head;
        int step = length / 2;
        while (step > 0) {
            cur = cur.next;
            step--;
        }
        ListNode nxt = cur.next;
        // 注意这里要断开
        cur.next = null;
        nxt = this.reverse(nxt);
        cur = head;
        while (nxt != null) {
            ListNode temp = cur.next;
            cur.next = nxt;
            nxt = nxt.next;
            cur.next.next = temp;
            cur = temp;
        }
        return;
        
        
    }
    
    public ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode next;
        while (head != null && head.next != null) {
            next = head.next;
            head.next = next.next;
            next.next = pre.next;
            pre.next = next;
        }
        return dummy.next;
    }
}
