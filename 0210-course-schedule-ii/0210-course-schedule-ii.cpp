class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> visited(numCourses, 0), ans;

        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }

        function<bool(int)> dfs = [&](int i) {
            if (visited[i] == 1) return false;
            if (visited[i] == 2) return true;
            
            visited[i] = 1;
            for (int j : g[i]) {
                if (!dfs(j)) return false;
            }
            visited[i] = 2;
            ans.push_back(i); 
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};