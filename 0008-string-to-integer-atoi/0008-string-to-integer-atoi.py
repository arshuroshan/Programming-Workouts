class Solution:
    def myAtoi(self, s: str) -> int:
        def clean_input(s: str) -> str:
            return s.lstrip()

        def get_sign(s: str, i: int) -> (int, int):
            if s[i] == '-':
                return -1, i + 1
            elif s[i] == '+':
                return 1, i + 1
            return 1, i

        def is_overflow(res: int, c: int, sign: int) -> bool:
            max_limit = 2**31 - 1 if sign > 0 else 2**31
            return res > (max_limit // 10) or (res == max_limit // 10 and c > 7)

        if not s:
            return 0
        
        s = clean_input(s)
        if not s:
            return 0

        i = 0
        sign, i = get_sign(s, i)
        res = 0

        while i < len(s) and s[i].isdigit():
            c = int(s[i])
            if is_overflow(res, c, sign):
                return 2**31 - 1 if sign > 0 else -(2**31)
            res = res * 10 + c
            i += 1

        return sign * res