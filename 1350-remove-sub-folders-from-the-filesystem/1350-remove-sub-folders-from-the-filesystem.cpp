class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
        for (int i = 1; i < folder.size(); i++) {
            int a = res.back().size(), b = folder[i].size();
            if (a >= b || res.back() != folder[i].substr(0, a) || folder[i][a] != '/')
                res.push_back(folder[i]);
        }
        return res;
    }
};
