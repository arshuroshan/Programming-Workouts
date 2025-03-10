from collections import deque

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        digit_to_letters = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        queue = deque([''])

        for digit in digits:
            level_size = len(queue)
            for _ in range(level_size):
                current_combination = queue.popleft()
                for letter in digit_to_letters[digit]:
                    queue.append(current_combination + letter)

        return list(queue)