class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        q = deque([(beginWord, 1)])
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        
        while q:
            currentWord, steps = q.popleft()
            for i in range(len(currentWord)):
                for char in alphabet:
                    if char != currentWord[i]:
                        newWord = currentWord[:i] + char + currentWord[i+1:]
                        if newWord == endWord:
                            return steps + 1
                        if newWord in wordSet:
                            q.append((newWord, steps + 1))
                            wordSet.remove(newWord)
        return 0