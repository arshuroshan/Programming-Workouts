class Solution {
    private ListNode frontPointer;
    
    public boolean isPalindrome(ListNode head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
    
    private boolean recursivelyCheck(ListNode currentNode) {
        if (currentNode == null) {
            return true;
        }
        
        if (!recursivelyCheck(currentNode.next)) {
            return false;
        }
        
        if (currentNode.val != frontPointer.val) {
            return false;
        }
        
        frontPointer = frontPointer.next;
        return true;
    }
}