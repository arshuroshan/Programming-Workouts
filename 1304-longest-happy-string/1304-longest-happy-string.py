class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        def add_next(counts, chars, result):
            if counts[0] >= counts[1] and counts[0] >= counts[2]:
                index = 0
            elif counts[1] >= counts[0] and counts[1] >= counts[2]:
                index = 1
            else:
                index = 2

            if counts[index] == 0:
                return False

            if len(result) >= 2 and result[-1] == result[-2] == chars[index]:
                if counts[(index + 1) % 3] > 0:
                    index = (index + 1) % 3
                elif counts[(index + 2) % 3] > 0:
                    index = (index + 2) % 3
                else:
                    return False
            
            result.append(chars[index])
            counts[index] -= 1
            return True

        counts = [a, b, c]
        chars = ['a', 'b', 'c']
        result = []

        while add_next(counts, chars, result):
            pass

        return ''.join(result)