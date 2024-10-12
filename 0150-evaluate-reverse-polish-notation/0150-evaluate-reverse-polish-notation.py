class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        for token in tokens:
            if token not in "+-*/":
                s.append(int(token))
            else:
                b, a = s.pop(), s.pop()
                if token == "+":
                    s.append(a + b)
                elif token == "-":
                    s.append(a - b)
                elif token == "*":
                    s.append(a * b)
                else:
                    s.append(int(a / b))
        return s[0]