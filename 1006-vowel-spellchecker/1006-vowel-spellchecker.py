class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def g(w):
            return "".join("*" if c in "aeiou" else c for c in w)

        s = set(wordlist)
        low, pat = {}, {}
        for w in wordlist:
            t = w.lower()
            if t not in low: low[t] = w
            p = g(t)
            if p not in pat: pat[p] = w

        res = []
        for q in queries:
            if q in s:
                res.append(q)
            else:
                t = q.lower()
                if t in low:
                    res.append(low[t])
                else:
                    p = g(t)
                    res.append(pat[p] if p in pat else "")
        return res