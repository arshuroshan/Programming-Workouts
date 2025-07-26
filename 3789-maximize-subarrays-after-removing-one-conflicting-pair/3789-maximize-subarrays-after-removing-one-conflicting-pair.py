class Solution:
  def maxSubarrays(self, n: int, conflictingPairs: list[list[int]]) -> int:
    res = 0
    m1 = m2 = 0
    g = [0] * (n + 1)
    c = [[] for _ in range(n + 1)]

    for a, b in conflictingPairs:
      c[max(a, b)].append(min(a, b))

    for r in range(1, n + 1):
      for l in c[r]:
        if l > m1:
          m2 = m1
          m1 = l
        elif l > m2:
          m2 = l
      res += r - m1
      g[m1] += m1 - m2

    return res + max(g)
