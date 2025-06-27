import java.util.*;

class Solution {
    private char[] input;

    public String longestSubsequenceRepeatedK(String s, int k) {
        input = s.toCharArray();
        int[] frequency = new int[26];

        for (char ch : input) {
            frequency[ch - 'a']++;
        }

        List<Character> candidates = new ArrayList<>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (frequency[ch - 'a'] >= k) {
                candidates.add(ch);
            }
        }

        Queue<String> queue = new LinkedList<>();
        queue.offer("");
        String result = "";

        while (!queue.isEmpty()) {
            String current = queue.poll();
            for (char ch : candidates) {
                String next = current + ch;
                if (isValid(next, k)) {
                    if (next.length() > result.length() || (next.length() == result.length() && next.compareTo(result) > 0)) {
                        result = next;
                    }
                    queue.offer(next);
                }
            }
        }

        return result;
    }

    private boolean isValid(String pattern, int k) {
        int index = 0, count = 0;

        for (char ch : input) {
            if (ch == pattern.charAt(index)) {
                index++;
                if (index == pattern.length()) {
                    count++;
                    if (count == k) return true;
                    index = 0;
                }
            }
        }

        return false;
    }
}
