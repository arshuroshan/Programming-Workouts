class Solution {
    struct Node {
        array<int, 26> next;
        int bestLen;
        int bestIdx;

        Node() : bestLen(INT_MAX), bestIdx(INT_MAX) {
            next.fill(-1);
        }
    };

    vector<Node> trie;

    void addWord(const string& word, int pos) {
        int cur = 0;

        if ((int)word.size() < trie[cur].bestLen) {
            trie[cur].bestLen = word.size();
            trie[cur].bestIdx = pos;
        }

        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[cur].next[c] == -1) {
                trie[cur].next[c] = trie.size();
                trie.emplace_back();
            }

            cur = trie[cur].next[c];

            if ((int)word.size() < trie[cur].bestLen) {
                trie[cur].bestLen = word.size();
                trie[cur].bestIdx = pos;
            }
        }
    }

    int findBest(const string& word) {
        int cur = 0;

        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[cur].next[c] == -1) {
                break;
            }

            cur = trie[cur].next[c];
        }

        return trie[cur].bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.emplace_back();

        for (int i = 0; i < wordsContainer.size(); ++i) {
            addWord(wordsContainer[i], i);
        }

        vector<int> result;
        result.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            result.push_back(findBest(q));
        }

        return result;
    }
};