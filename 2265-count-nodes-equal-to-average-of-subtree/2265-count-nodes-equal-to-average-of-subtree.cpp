class Solution {
    pair<long long, int> solve(TreeNode* node, int& result) {
        if (node == nullptr)
            return {0, 0};

        auto left = solve(node->left, result);
        auto right = solve(node->right, result);

        long long total = node->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        result += (total / count == node->val);

        return {total, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        solve(root, result);
        return result;
    }
};