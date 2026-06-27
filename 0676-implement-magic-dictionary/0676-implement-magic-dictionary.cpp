class Trie {
public:
    Trie* next[26];
    bool end;

    Trie() {
        memset(next, 0, sizeof(next));
        end = false;
    }

    void insert(string &word) {
        Trie* cur = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->next[idx])
                cur->next[idx] = new Trie();
            cur = cur->next[idx];
        }
        cur->end = true;
    }

    bool solve(string &word, int pos, bool changed) {
        if (pos == word.size())
            return changed && end;

        int idx = word[pos] - 'a';

        for (int i = 0; i < 26; i++) {
            if (!next[i]) continue;

            if (i == idx) {
                if (next[i]->solve(word, pos + 1, changed))
                    return true;
            } else if (!changed) {
                if (next[i]->solve(word, pos + 1, true))
                    return true;
            }
        }

        return false;
    }

    bool search(string &word) {
        return solve(word, 0, false);
    }
};

class MagicDictionary {
    Trie* root;

public:
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &word : dictionary)
            root->insert(word);
    }

    bool search(string searchWord) {
        return root->search(searchWord);
    }
};