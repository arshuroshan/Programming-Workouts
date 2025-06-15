class Solution {
    public int maxDiff(int num) {
        char[] numChars = String.valueOf(num).toCharArray();
        char[] maxNum = numChars.clone();
        char[] minNum = numChars.clone();
        
        for (int i = 0; i < maxNum.length; i++) {
            if (maxNum[i] != '9') {
                char target = maxNum[i];
                for (int j = i; j < maxNum.length; j++) {
                    if (maxNum[j] == target) {
                        maxNum[j] = '9';
                    }
                }
                break;
            }
        }
        
        if (minNum[0] != '1') {
            char target = minNum[0];
            for (int j = 0; j < minNum.length; j++) {
                if (minNum[j] == target) {
                    minNum[j] = '1';
                }
            }
        } else {
            for (int i = 1; i < minNum.length; i++) {
                if (minNum[i] != '0' && minNum[i] != '1') {
                    char target = minNum[i];
                    for (int j = i; j < minNum.length; j++) {
                        if (minNum[j] == target) {
                            minNum[j] = '0';
                        }
                    }
                    break;
                }
            }
        }
        
        return Integer.parseInt(new String(maxNum)) - Integer.parseInt(new String(minNum));
    }
}