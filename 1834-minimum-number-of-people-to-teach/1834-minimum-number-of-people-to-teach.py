class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        s = set()
        for u, v in friendships:
            if not set(languages[u - 1]) & set(languages[v - 1]):
                s.add(u)
                s.add(v)
        cnt = Counter(l for u in s for l in languages[u - 1])
        return len(s) - max(cnt.values(), default=0)
