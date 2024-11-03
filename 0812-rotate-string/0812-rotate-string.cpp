class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (isRotation(s, goal, i)) {
                return true;
            }
        }

        return false;
    }

private:
    bool isRotation(const string& s, const string& goal, int pos) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[(i + pos) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }
};