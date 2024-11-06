class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end;

    TrieNode() : is_end(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->is_end = true;
    }

    bool search(const string& word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->is_end;
        }

        char c = word[index];
        if (c != '.') {
            if (node->children.find(c) != node->children.end()) {
                return dfs(word, index + 1, node->children[c]);
            }
        } else {
            for (auto& pair : node->children) {
                if (dfs(word, index + 1, pair.second)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */