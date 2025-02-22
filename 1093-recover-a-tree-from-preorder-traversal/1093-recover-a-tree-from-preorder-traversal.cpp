/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int index = 0;
        return helper(S, index, 0);
    }

private:
    TreeNode* helper(const string& S, int& index, int depth) {
        if (index >= S.length()) return nullptr;

        int currentDepth = 0;
        while (index + currentDepth < S.length() && S[index + currentDepth] == '-') {
            currentDepth++;
        }

        if (currentDepth != depth) {
            return nullptr;
        }

        index += currentDepth;

        int num = 0;
        while (index < S.length() && isdigit(S[index])) {
            num = num * 10 + (S[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(num);

        node->left = helper(S, index, depth + 1);
        node->right = helper(S, index, depth + 1);

        return node;
    }
};