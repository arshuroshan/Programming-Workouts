class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new List[numCourses];
        Arrays.setAll(graph, k -> new ArrayList<>());

        for (int[] prerequisite : prerequisites) {
            graph[prerequisite[1]].add(prerequisite[0]);
        }

        int[] visited = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, visited, i)) {
                return false;
            }
        }

        return true;
    }

    private boolean hasCycle(List<Integer>[] graph, int[] visited, int node) {
        if (visited[node] == 1) {
            return true;
        }
        if (visited[node] == 2) {
            return false;
        }

        visited[node] = 1;

        for (int neighbor : graph[node]) {
            if (hasCycle(graph, visited, neighbor)) {
                return true;
            }
        }

        visited[node] = 2;
        return false;
    }
}