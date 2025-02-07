from collections import defaultdict

class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball_color = {}
        color_count = defaultdict(int)
        unique_colors = set()
        ans = []
        
        for x, y in queries:
            if x in ball_color:
                prev_color = ball_color[x]
                color_count[prev_color] -= 1
                if color_count[prev_color] == 0:
                    unique_colors.discard(prev_color)

            ball_color[x] = y
            color_count[y] += 1
            unique_colors.add(y)
            
            ans.append(len(unique_colors))
        
        return ans