#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int m = n / 2;
        string prefix = target.substr(0, m);

        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        string half;
        int fail = -1;

        for (int i = 0; i < m; i++) {
            int x = prefix[i] - 'a';

            if (halfCnt[x] > 0) {
                half += prefix[i];
                halfCnt[x]--;
            } else {
                fail = i;
                break;
            }
        }

        if (fail == -1) {
            string candidate = makePalindrome(half, mid);

            if (candidate > target)
                return candidate;

            string nextHalf = half;

            if (next_permutation(nextHalf.begin(), nextHalf.end()))
                return makePalindrome(nextHalf, mid);

            return "";
        }

        int x = prefix[fail] - 'a';

        for (int c = x + 1; c < 26; c++) {
            if (halfCnt[c] == 0)
                continue;

            string result = half;
            result += char('a' + c);
            halfCnt[c]--;

            for (int j = 0; j < 26; j++)
                result.append(halfCnt[j], char('a' + j));

            return makePalindrome(result, mid);
        }

        for (int i = fail - 1; i >= 0; i--) {
            int current = half[i] - 'a';
            halfCnt[current]++;

            for (int c = current + 1; c < 26; c++) {
                if (halfCnt[c] == 0)
                    continue;

                string result = half.substr(0, i);
                result += char('a' + c);
                halfCnt[c]--;

                for (int j = 0; j < 26; j++)
                    result.append(halfCnt[j], char('a' + j));

                return makePalindrome(result, mid);
            }

            half.resize(i);
        }

        return "";
    }

private:
    string makePalindrome(const string& half, char mid) {
        string result = half;

        if (mid)
            result += mid;

        for (int i = half.size() - 1; i >= 0; i--)
            result += half[i];

        return result;
    }
};