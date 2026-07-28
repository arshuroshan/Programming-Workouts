class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;

        string res(s.size(), ' ');
        int l = 0, r = s.size() - 1;

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 1) {
                res[l++] = char('a' + i);
                res[r--] = char('a' + i);
                freq[i] -= 2;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                res[l] = char('a' + i);
                break;
            }
        }

        return res;
    }
};