class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        order = sorted(range(len(positions)), key=lambda x: positions[x])
        right_moving = []

        for robot in order:
            if directions[robot] == "R":
                right_moving.append(robot)
            else:
                while right_moving and healths[robot] > 0:
                    last_right = right_moving[-1]

                    if healths[last_right] > healths[robot]:
                        healths[last_right] -= 1
                        healths[robot] = 0
                    elif healths[last_right] < healths[robot]:
                        healths[robot] -= 1
                        healths[last_right] = 0
                        right_moving.pop()
                    else:
                        healths[robot] = 0
                        healths[last_right] = 0
                        right_moving.pop()
                        break

        survivors = []
        for health in healths:
            if health > 0:
                survivors.append(health)

        return survivors