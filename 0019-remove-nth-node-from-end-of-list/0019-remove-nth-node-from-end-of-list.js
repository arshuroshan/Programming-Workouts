var removeNthFromEnd = function(head, n) {
    let length = 0;
    let current = head;
    
    while (current !== null) {
        length++;
        current = current.next;
    }

    const position = length - n;

    const dummy = new ListNode(0, head);
    current = dummy;

    for (let i = 0; i < position; i++) {
        current = current.next;
    }
    
    current.next = current.next.next;
    
    return dummy.next;
};