/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) return nullptr;

        unordered_map<int, int> postMap;
        for (int i = 0; i < postorder.size(); ++i) {
            postMap[postorder[i]] = i;
        }

        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);

            int postIndex = postMap[preorder[i]];

            int topPostIndex = postMap[stk.top()->val];

            if (postIndex < topPostIndex) {
                stk.top()->left = node;
            } else {
                while (!stk.empty() && postMap[stk.top()->val] < postIndex) {
                    stk.pop();
                }
                stk.top()->right = node;
            }

            stk.push(node);
        }

        return root;
    }
};