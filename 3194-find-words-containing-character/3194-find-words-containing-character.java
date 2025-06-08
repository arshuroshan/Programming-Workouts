class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<>();
        int index = 0;
        for (String word : words) {
            if (word.indexOf(x) != -1) {
                result.add(index);
            }
            index++;
        }
        return result;
    }
}