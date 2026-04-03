from typing import List
from bisect import bisect_left
from functools import lru_cache

class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        pairs = sorted(zip(robots, distance))
        walls.sort()
        total_robots = len(pairs)

        @lru_cache(None)
        def solve(index: int, state: int) -> int:
            if index < 0:
                return 0

            robot_pos, robot_dist = pairs[index]

            # Option 1: Cover to the left
            left_start = robot_pos - robot_dist
            if index > 0:
                left_start = max(left_start, pairs[index - 1][0] + 1)

            left_walls_start = bisect_left(walls, left_start)
            left_walls_end = bisect_left(walls, robot_pos + 1)

            take_left = solve(index - 1, 0) + (left_walls_end - left_walls_start)

            # Option 2: Cover to the right
            right_end = robot_pos + robot_dist
            if index + 1 < total_robots:
                next_robot_pos, next_robot_dist = pairs[index + 1]

                if state == 0:
                    right_end = min(right_end, next_robot_pos - next_robot_dist - 1)
                else:
                    right_end = min(right_end, next_robot_pos - 1)

            right_walls_start = bisect_left(walls, robot_pos)
            right_walls_end = bisect_left(walls, right_end + 1)

            take_right = solve(index - 1, 1) + (right_walls_end - right_walls_start)

            return max(take_left, take_right)

        result = solve(total_robots - 1, 1)
        solve.cache_clear()
        return result