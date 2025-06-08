import java.util.*;

class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        List<Integer>[] tree1 = buildTree(edges1);
        List<Integer>[] tree2 = buildTree(edges2);
        
        int[] color1 = new int[tree1.length];
        int[] color2 = new int[tree2.length];
        int[] colorCount1 = new int[2];
        int[] colorCount2 = new int[2];
        
        colorNodes(tree2, 0, -1, color2, 0, colorCount2);
        colorNodes(tree1, 0, -1, color1, 0, colorCount1);
        
        int maxColor2 = Math.max(colorCount2[0], colorCount2[1]);
        int[] result = new int[tree1.length];
        
        for (int i = 0; i < tree1.length; i++) {
            result[i] = maxColor2 + colorCount1[color1[i]];
        }
        
        return result;
    }

    private List<Integer>[] buildTree(int[][] edges) {
        int n = edges.length + 1;
        List<Integer>[] tree = new List[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            tree[a].add(b);
            tree[b].add(a);
        }
        return tree;
    }

    private void colorNodes(List<Integer>[] tree, int node, int parent, 
                          int[] colors, int currentColor, int[] colorCount) {
        colors[node] = currentColor;
        colorCount[currentColor]++;
        
        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                colorNodes(tree, neighbor, node, colors, currentColor ^ 1, colorCount);
            }
        }
    }
}