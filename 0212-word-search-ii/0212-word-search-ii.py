class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.word = word

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(node: TrieNode, i: int, j: int):
            char = board[i][j]
            if char not in node.children:
                return
            node = node.children[char]
            if node.word:
                ans.append(node.word)
                node.word = None
            
            board[i][j] = '#'
            for x_offset, y_offset in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                x, y = i + x_offset, j + y_offset
                if 0 <= x < m and 0 <= y < n and board[x][y] != '#':
                    dfs(node, x, y)
            board[i][j] = char

        trie = Trie()
        for word in words:
            trie.insert(word)

        m, n = len(board), len(board[0])
        ans = []

        for i in range(m):
            for j in range(n):
                dfs(trie.root, i, j)

        return ans