class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        int index = 1;

        while (head && head->next && head->next->next) {
            int prev = head->val;
            int curr = head->next->val;
            int next = head->next->next->val;

            if ((curr > prev && curr > next) ||
                (curr < prev && curr < next)) {
                points.push_back(index);
            }

            head = head->next;
            index++;
        }

        if (points.size() < 2)
            return {-1, -1};

        int minimum = INT_MAX;

        for (int i = 1; i < points.size(); i++)
            minimum = min(minimum, points[i] - points[i - 1]);

        int maximum = points.back() - points.front();

        return {minimum, maximum};
    }
};