# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        
        while True:
            node = pre
            for _ in range(k):
                node = node.next
                if not node:
                    return dummy.next
            
            cur = pre.next
            nxt = cur.next
            for _ in range(k - 1):
                temp = nxt.next
                nxt.next = cur
                cur = nxt
                nxt = temp
            
            tail = pre.next
            tail.next = nxt
            pre.next = cur
            
            pre = tail