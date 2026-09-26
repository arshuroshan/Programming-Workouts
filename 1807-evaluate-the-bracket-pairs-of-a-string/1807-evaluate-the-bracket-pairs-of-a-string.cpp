class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (const auto& item : knowledge)
            mp.emplace(item[0], item[1]);

        string res;
        string key;
        bool inside = false;

        for (char ch : s) {
            if (ch == '(') {
                inside = true;
                key.clear();
            } 
            else if (ch == ')') {
                auto it = mp.find(key);
                res += (it != mp.end()) ? it->second : "?";
                inside = false;
            } 
            else if (inside) {
                key.push_back(ch);
            } 
            else {
                res.push_back(ch);
            }
        }

        return res;
    }
};