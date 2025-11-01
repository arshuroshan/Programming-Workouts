class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        s = set(nums)
        d = ListNode(0, head)
        p = d
        while p.next:
            if p.next.val in s:
                p.next = p.next.next
            else:
                p = p.next
        return d.next