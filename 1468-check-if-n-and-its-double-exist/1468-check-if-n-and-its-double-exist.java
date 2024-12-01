class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        for (int x : arr) {
            if (map.containsKey(x * 2)) {
                if (x == 0 && map.get(x) > 1) {
                    return true;
                }
                else if (x != 0) {
                    return true;
                }
            }
        }
        return false;
    }
}