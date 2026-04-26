class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        while (!st.empty()) {
            auto [node, val] = st.top();
            st.pop();
            val = (val << 1) | node->val;
            if (!node->left && !node->right) {
                res += val;
            } else {
                if (node->right) st.push({node->right, val});
                if (node->left) st.push({node->left, val});
            }
        }
        return res;
    }
};