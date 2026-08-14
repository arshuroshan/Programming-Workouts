class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {}, left = 0, result = 0;

        for (int right = 0; right < s.length(); ++right) {
            ++freq[s[right] - 'a'];

            if (freq[s[right] - 'a'] > 2) {
                while (s[left] != s[right]) {
                    --freq[s[left] - 'a'];
                    ++left;
                }
                --freq[s[left] - 'a'];
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};