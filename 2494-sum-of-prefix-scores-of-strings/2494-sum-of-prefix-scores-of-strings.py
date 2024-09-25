class TrieNode:
    def __init__(self):
        self.children = {}
        self.cnt = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.cnt += 1

    def search(self, word):
        node = self.root
        total_score = 0
        for char in word:
            if char not in node.children:
                break
            node = node.children[char]
            total_score += node.cnt
        return total_score

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        return [trie.search(word) for word in words]