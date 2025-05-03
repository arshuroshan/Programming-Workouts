class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def check(target):
            rotations_top = rotations_bottom = 0
            for top, bottom in zip(tops, bottoms):
                if top != target and bottom != target:
                    return float('inf')
                if top != target:
                    rotations_top += 1
                if bottom != target:
                    rotations_bottom += 1
            return min(rotations_top, rotations_bottom)

        candidates = {tops[0], bottoms[0]}
        min_rotations = float('inf')
        
        for candidate in candidates:
            rotations = check(candidate)
            if rotations < min_rotations:
                min_rotations = rotations
        
        return min_rotations if min_rotations != float('inf') else -1