from math import isqrt
from itertools import pairwise

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def sieve(n):
            is_prime = [True] * (n + 1)
            is_prime[0] = is_prime[1] = False
            for i in range(2, isqrt(n) + 1):
                if is_prime[i]:
                    for j in range(i * i, n + 1, i):
                        is_prime[j] = False
            return [x for x, prime in enumerate(is_prime) if prime]

        primes = sieve(right)

        primes_in_range = [p for p in primes if left <= p <= right]

        min_diff = float('inf')
        result = [-1, -1]

        for a, b in pairwise(primes_in_range):
            if (diff := b - a) < min_diff:
                min_diff = diff
                result = [a, b]

        return result