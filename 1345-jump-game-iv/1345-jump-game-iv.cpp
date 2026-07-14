class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[arr[i]].push_back(i);
        }

        unordered_set<int> left{0};
        unordered_set<int> right{n - 1};
        vector<bool> visited(n, false);

        visited[0] = true;
        visited[n - 1] = true;

        int jumps = 0;

        while (!left.empty() && !right.empty()) {
            if (left.size() > right.size()) {
                swap(left, right);
            }

            unordered_set<int> next;

            for (int index : left) {
                vector<int> neighbours = {index - 1, index + 1};

                auto it = positions.find(arr[index]);
                if (it != positions.end()) {
                    neighbours.insert(
                        neighbours.end(),
                        it->second.begin(),
                        it->second.end()
                    );
                    positions.erase(it);
                }

                for (int neighbour : neighbours) {
                    if (neighbour < 0 || neighbour >= n) continue;
                    if (right.count(neighbour)) return jumps + 1;

                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        next.insert(neighbour);
                    }
                }
            }

            left = move(next);
            ++jumps;
        }

        return -1;
    }
};