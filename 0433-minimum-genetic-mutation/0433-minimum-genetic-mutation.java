class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> geneBank = new HashSet<>(Arrays.asList(bank));
        if (!geneBank.contains(endGene)) return -1;

        char[] mutations = {'A', 'C', 'G', 'T'};
        Queue<String> queue = new LinkedList<>();
        queue.offer(startGene);
        Set<String> visited = new HashSet<>();
        visited.add(startGene);

        int depth = 0;
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                String currentGene = queue.poll();
                if (currentGene.equals(endGene)) {
                    return depth;
                }
                char[] currentArr = currentGene.toCharArray();
                for (int j = 0; j < currentArr.length; j++) {
                    char originalChar = currentArr[j];
                    for (char mutation : mutations) {
                        if (mutation != originalChar) {
                            currentArr[j] = mutation;
                            String mutatedGene = new String(currentArr);
                            if (geneBank.contains(mutatedGene) && !visited.contains(mutatedGene)) {
                                queue.offer(mutatedGene);
                                visited.add(mutatedGene);
                            }
                        }
                    }
                    currentArr[j] = originalChar;
                }
            }
            depth++;
        }
        return -1;
    }
}