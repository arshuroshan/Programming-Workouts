class Solution {
    public int maxDistance(String directions, int k) {
        char[] dirs = directions.toCharArray();
        int maxDistance = 0;
        
        maxDistance = Math.max(maxDistance, calculateMaxDistance(dirs, k, 'S', 'E'));
        maxDistance = Math.max(maxDistance, calculateMaxDistance(dirs, k, 'S', 'W'));
        maxDistance = Math.max(maxDistance, calculateMaxDistance(dirs, k, 'N', 'E'));
        maxDistance = Math.max(maxDistance, calculateMaxDistance(dirs, k, 'N', 'W'));
        
        return maxDistance;
    }

    private int calculateMaxDistance(char[] directions, int maxChanges, char dir1, char dir2) {
        int currentDistance = 0;
        int maxAchievableDistance = 0;
        int changesUsed = 0;
        
        for (char dir : directions) {
            if (dir == dir1 || dir == dir2) {
                currentDistance++;
            } else if (changesUsed < maxChanges) {
                currentDistance++;
                changesUsed++;
            } else {
                currentDistance--;
            }
            
            maxAchievableDistance = Math.max(maxAchievableDistance, currentDistance);
        }
        
        return maxAchievableDistance;
    }
}