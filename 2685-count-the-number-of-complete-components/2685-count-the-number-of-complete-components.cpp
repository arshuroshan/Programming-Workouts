class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> visited(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int result = 0;
        
        for (int start = 0; start < n; ++start) {
            if (visited[start]) continue;
            
            queue<int> q;
            q.push(start);
            visited[start] = 1;
            
            int vertices = 0;
            int degreeSum = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                ++vertices;
                degreeSum += graph[node].size();
                
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            
            if (degreeSum == vertices * (vertices - 1)) {
                ++result;
            }
        }
        
        return result;
    }
};