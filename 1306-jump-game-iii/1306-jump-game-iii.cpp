class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int idx = st.top();
            st.pop();

            if (vis[idx]) continue;
            vis[idx] = true;

            if (arr[idx] == 0) return true;

            int left = idx - arr[idx];
            int right = idx + arr[idx];

            if (left >= 0 && !vis[left]) {
                st.push(left);
            }

            if (right < n && !vis[right]) {
                st.push(right);
            }
        }

        return false;
    }
};