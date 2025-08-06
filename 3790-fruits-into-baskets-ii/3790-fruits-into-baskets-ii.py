class Solution:
    def numOfUnplacedFruits(self, fruits, baskets):
        n = len(fruits)
        used = [0] * n
        count = n
        for f in fruits:
            for i in range(n):
                if baskets[i] >= f and not used[i]:
                    used[i] = 1
                    count -= 1
                    break
        return count
