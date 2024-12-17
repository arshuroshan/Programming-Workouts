from collections import Counter
from string import ascii_lowercase

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = Counter(s)

        result = []

        chars = sorted(freq.keys(), reverse=True)

        while chars:

            char = chars[0]
            count = min(repeatLimit, freq[char])
            result.append(char * count)
            freq[char] -= count
            
            if freq[char] == 0:
                chars.pop(0)
            
            if freq[char] > 0:
                if len(chars) == 1:
                    break
                next_char = chars[1]
                result.append(next_char)
                freq[next_char] -= 1
                if freq[next_char] == 0:
                    chars.pop(1)
        
        return ''.join(result)