class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        res = []
        if (numerator > 0) ^ (denominator > 0):
            res.append("-")
        a, b = abs(numerator), abs(denominator)
        res.append(str(a // b))
        a %= b
        if a == 0:
            return "".join(res)
        res.append(".")
        seen = {}
        while a:
            if a in seen:
                res.insert(seen[a], "(")
                res.append(")")
                break
            seen[a] = len(res)
            a *= 10
            res.append(str(a // b))
            a %= b
        return "".join(res)