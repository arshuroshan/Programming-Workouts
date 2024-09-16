import java.util.*;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }

        int n = timePoints.size();
        int[] minutes = new int[n];
        for (int i = 0; i < n; ++i) {
            String[] time = timePoints.get(i).split(":");
            minutes[i] = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
        }

        Arrays.sort(minutes);

        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < n; ++i) {
            minDiff = Math.min(minDiff, minutes[i] - minutes[i - 1]);
        }

        minDiff = Math.min(minDiff, (1440 - minutes[n - 1] + minutes[0]));

        return minDiff;
    }
}