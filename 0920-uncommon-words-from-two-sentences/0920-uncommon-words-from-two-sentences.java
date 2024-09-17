import java.util.HashSet;
import java.util.Set;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Set<String> wordsInS1 = new HashSet<>();
        Set<String> wordsInS2 = new HashSet<>();
        Set<String> uncommonWords = new HashSet<>();

        String[] wordsArray1 = s1.split(" ");
        String[] wordsArray2 = s2.split(" ");

        for (String word : wordsArray1) {
            if (!wordsInS1.add(word)) {
                uncommonWords.remove(word);
            } else {
                uncommonWords.add(word);
            }
        }
        
        for (String word : wordsArray2) {
            if (!wordsInS2.add(word)) {
                uncommonWords.remove(word);
            } else {
                uncommonWords.add(word);
            }
        }
        
        wordsInS1.retainAll(wordsInS2);
        uncommonWords.removeAll(wordsInS1);
        
        return uncommonWords.toArray(new String[0]);
    }
}