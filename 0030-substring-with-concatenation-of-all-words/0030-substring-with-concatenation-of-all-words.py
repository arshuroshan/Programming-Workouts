class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        from collections import Counter
        
        word_count = Counter(words)
        word_length = len(words[0])
        num_words = len(words)
        total_length = num_words * word_length
        ans = []
        
        for i in range(word_length):
            left = i
            right = i
            current_count = Counter()
            count = 0
            
            while right + word_length <= len(s):
                word = s[right:right + word_length]
                right += word_length
                
                if word in word_count:
                    current_count[word] += 1
                    count += 1
                    
                    # Check if we have more instances of the word than allowed
                    while current_count[word] > word_count[word]:
                        left_word = s[left:left + word_length]
                        current_count[left_word] -= 1
                        left += word_length
                        count -= 1
                    
                    # If the count of words matches the number of words
                    if count == num_words:
                        ans.append(left)
                else:
                    # Reset if the word is not in the original list
                    left = right
                    current_count.clear()
                    count = 0
                    
        return ans