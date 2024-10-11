class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        events = []
        for idx, (arrive, leave) in enumerate(times):
            events.append((arrive, 1, idx))
            events.append((leave, 0, idx))
        events.sort()

        free_chairs = []
        heapq.heapify(free_chairs)
        occupied = {}

        for time, event_type, friend in events:
            if event_type == 1:
                if free_chairs:
                    chair = heapq.heappop(free_chairs)
                else:
                    chair = len(occupied)
                occupied[friend] = chair
                if friend == targetFriend:
                    return chair
            else:
                heapq.heappush(free_chairs, occupied.pop(friend))

        return -1