class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        queue = deque([0])
        visited = set()

        while queue:
            start = queue.popleft()
            if start in visited:
                continue
            visited.add(start)

            for end in range(start + 1, len(s) + 1):
                if s[start:end] in word_set:
                    queue.append(end)
                    if end == len(s):
                        return True
        return False