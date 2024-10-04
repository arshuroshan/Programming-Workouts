class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        target_sum = skill[0] + skill[-1]
        total_skill = 0
        
        for i in range(len(skill) // 2):
            if skill[i] + skill[-i-1] != target_sum:
                return -1
            total_skill += skill[i] * skill[-i-1]
        
        return total_skill