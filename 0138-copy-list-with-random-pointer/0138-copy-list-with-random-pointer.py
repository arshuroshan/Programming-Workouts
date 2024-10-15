class Solution:
    def copyRandomList(self, head: "Node") -> "Node":
        if not head:
            return None

        cur = head
        while cur:
            new_node = Node(cur.val)
            new_node.next = cur.next
            cur.next = new_node
            cur = new_node.next

        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next

        cur_old = head
        cur_new = head.next
        new_head = head.next
        while cur_old:
            cur_old.next = cur_old.next.next
            if cur_new.next:
                cur_new.next = cur_new.next.next
            cur_old = cur_old.next
            cur_new = cur_new.next

        return new_head