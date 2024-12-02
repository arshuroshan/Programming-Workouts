class Solution:
    def myPow(self, x: float, n: int) -> float:
        def recursivePow(a: float, n: int) -> float:
            if n == 0:
                return 1
            if n % 2 == 0:
                half = recursivePow(a, n // 2)
                return half * half
            else:
                return a * recursivePow(a, n - 1)
        
        return recursivePow(x, n) if n >= 0 else 1 / recursivePow(x, -n)