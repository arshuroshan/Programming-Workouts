class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int cur = st.top();
                st.pop();

                int score = cur == 0 ? 1 : 2 * cur;
                st.top() += score;
            }
        }

        return st.top();
    }
};