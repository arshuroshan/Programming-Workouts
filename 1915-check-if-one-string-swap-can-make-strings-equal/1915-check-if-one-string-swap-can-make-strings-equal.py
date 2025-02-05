class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True

        diff_indices = [i for i in range(len(s1)) if s1[i] != s2[i]]

        if len(diff_indices) == 2:
            i, j = diff_indices
            s1_swapped = list(s1)
            s1_swapped[i], s1_swapped[j] = s1_swapped[j], s1_swapped[i]
            return ''.join(s1_swapped) == s2
        
        return False