class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        def evaluate(expr: str) -> bool:
            if expr == 't':
                return True
            elif expr == 'f':
                return False

            operator = expr[0]
            sub_exprs = []
            level, start = 0, 2

            for i in range(2, len(expr) - 1):
                if expr[i] == '(':
                    level += 1
                elif expr[i] == ')':
                    level -= 1

                if expr[i] == ',' and level == 0:
                    sub_exprs.append(expr[start:i])
                    start = i + 1
            sub_exprs.append(expr[start:len(expr) - 1])

            if operator == '!':
                return not evaluate(sub_exprs[0])
            elif operator == '&':
                return all(evaluate(sub_expr) for sub_expr in sub_exprs)
            elif operator == '|':
                return any(evaluate(sub_expr) for sub_expr in sub_exprs)

        return evaluate(expression)