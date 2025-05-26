import java.util.*;

class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        List<Integer>[] graph = new List[n];
        int[] inDegree = new int[n];
        
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            inDegree[edge[1]]++;
        }
        
        int[][] colorCounts = new int[n][26];
        Queue<Integer> queue = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
                colorCounts[i][colors.charAt(i) - 'a'] = 1;
            }
        }
        
        int processedNodes = 0;
        int maxColorValue = 1;
        
        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            processedNodes++;
            
            for (int neighbor : graph[currentNode]) {
                inDegree[neighbor]--;
                
                for (int color = 0; color < 26; color++) {
                    int newCount = colorCounts[currentNode][color] + 
                                  (colors.charAt(neighbor) - 'a' == color ? 1 : 0);
                    if (newCount > colorCounts[neighbor][color]) {
                        colorCounts[neighbor][color] = newCount;
                        maxColorValue = Math.max(maxColorValue, newCount);
                    }
                }
                
                if (inDegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }
        
        return processedNodes == n ? maxColorValue : -1;
    }
}