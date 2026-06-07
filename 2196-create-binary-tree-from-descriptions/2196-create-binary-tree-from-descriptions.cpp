class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> indegree;

        auto getNode = [&](int value) {
            if (!mp[value]) mp[value] = new TreeNode(value);
            return mp[value];
        };

        for (auto& d : descriptions) {
            TreeNode* parent = getNode(d[0]);
            TreeNode* child = getNode(d[1]);

            indegree[d[1]]++;
            if (!indegree.count(d[0])) indegree[d[0]] = 0;

            d[2] ? parent->left = child : parent->right = child;
        }

        for (auto& [value, node] : mp) {
            if (indegree[value] == 0) return node;
        }

        return nullptr;
    }
};