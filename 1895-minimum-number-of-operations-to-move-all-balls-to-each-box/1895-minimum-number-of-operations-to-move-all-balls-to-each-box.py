class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n
        count = 0
        ops = 0

        for i in range(n):
            res[i] += ops
            if boxes[i] == '1':
                count += 1
            ops += count

        count = 0
        ops = 0

        for i in range(n - 1, -1, -1):
            res[i] += ops
            if boxes[i] == '1':
                count += 1
            ops += count

        return res