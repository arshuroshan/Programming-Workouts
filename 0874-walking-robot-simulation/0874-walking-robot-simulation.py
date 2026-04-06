class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Directions: North, East, South, West
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        obstacle_set = set(map(tuple, obstacles))
        
        x, y = 0, 0
        direction_idx = 0
        max_distance = 0
        
        for command in commands:
            if command == -2:  # turn left
                direction_idx = (direction_idx - 1) % 4
            elif command == -1:  # turn right
                direction_idx = (direction_idx + 1) % 4
            else:
                dx, dy = directions[direction_idx]
                
                for _ in range(command):
                    next_x = x + dx
                    next_y = y + dy
                    
                    if (next_x, next_y) in obstacle_set:
                        break
                    
                    x, y = next_x, next_y
                    max_distance = max(max_distance, x*x + y*y)
        
        return max_distance