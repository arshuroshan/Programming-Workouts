class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> q;
        q.push(0);

        for (int i = 1; i < n; i++) {
            while (!q.empty() && q.front() < i - maxJump) {
                q.pop();
            }

            if (s[i] == '0' && !q.empty() && q.front() <= i - minJump) {
                q.push(i);
            }
        }

        return !q.empty() && q.back() == n - 1;
    }
};