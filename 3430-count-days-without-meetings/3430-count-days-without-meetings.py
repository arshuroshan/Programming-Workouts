class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        if not meetings:
            return days

        meetings.sort()

        merged = []
        for meeting in meetings:
            if not merged or merged[-1][1] < meeting[0]:
                merged.append(meeting)
            else:
                merged[-1][1] = max(merged[-1][1], meeting[1])

        free_days = 0
        prev_end = 0

        for interval in merged:
            start, end = interval
            if start > prev_end:
                free_days += start - prev_end - 1
            prev_end = max(prev_end, end)
        free_days += days - prev_end

        return free_days