# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        def split_list(head):
            slow, fast = head, head.next
            while fast and fast.next:
                slow, fast = slow.next, fast.next.next
            mid = slow.next
            slow.next = None
            return head, mid
        
        def merge_sorted_lists(l1, l2):
            dummy = ListNode()
            current = dummy
            while l1 and l2:
                if l1.val <= l2.val:
                    current.next = l1
                    l1 = l1.next
                else:
                    current.next = l2
                    l2 = l2.next
                current = current.next
            current.next = l1 or l2
            return dummy.next
        
        left, right = split_list(head)
        sorted_left = self.sortList(left)
        sorted_right = self.sortList(right)
        
        return merge_sorted_lists(sorted_left, sorted_right)