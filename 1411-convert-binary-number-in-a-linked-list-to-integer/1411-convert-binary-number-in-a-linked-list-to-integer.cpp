class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int r = 0;
        while (head) {
            r = (r << 1) | head->val;
            head = head->next;
        }
        return r;
    }
};
