class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder filtered = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                filtered.append(Character.toLowerCase(c));
            }
        }
        String filteredStr = filtered.toString();
        int left = 0, right = filteredStr.length() - 1;
        
        while (left < right) {
            if (filteredStr.charAt(left) != filteredStr.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
}