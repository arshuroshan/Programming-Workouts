#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                cnt[x]--;
                ans += target[i];
            } else {
                int bigger = x + 1;

                while (bigger < 26 && cnt[bigger] == 0)
                    bigger++;

                if (bigger < 26) {
                    ans += char('a' + bigger);
                    cnt[bigger]--;

                    for (int c = 0; c < 26; c++)
                        ans.append(cnt[c], char('a' + c));

                    return ans;
                }

                break;
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            int current = ans[i] - 'a';
            cnt[current]++;

            int bigger = current + 1;

            while (bigger < 26 && cnt[bigger] == 0)
                bigger++;

            if (bigger < 26) {
                string result = ans.substr(0, i);
                result += char('a' + bigger);
                cnt[bigger]--;

                for (int c = 0; c < 26; c++)
                    result.append(cnt[c], char('a' + c));

                return result;
            }
        }

        return "";
    }
};