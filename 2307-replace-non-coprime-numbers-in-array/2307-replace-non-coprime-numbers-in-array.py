class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        s = []
        for v in nums:
            s.append(v)
            while len(s) > 1:
                a, b = s[-2:]
                g = gcd(a, b)
                if g == 1:
                    break
                s.pop()
                s[-1] = a * b // g
        return s