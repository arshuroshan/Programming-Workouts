import java.util.*;

class Solution {
    private static final int MOD = (int) 1e9 + 7;
    private int m;
    
    public int colorTheGrid(int m, int n) {
        this.m = m;
        List<Integer> validStates = generateValidStates();
        Map<Integer, List<Integer>> transitions = buildTransitions(validStates);
        Map<Integer, Integer> dp = new HashMap<>();
        for (int state : validStates) {
            dp.put(state, 1);
        }
        for (int col = 1; col < n; col++) {
            Map<Integer, Integer> newDp = new HashMap<>();
            for (int current : validStates) {
                int sum = 0;
                for (int prev : transitions.getOrDefault(current, Collections.emptyList())) {
                    sum = (sum + dp.getOrDefault(prev, 0)) % MOD;
                }
                newDp.put(current, sum);
            }
            dp = newDp;
        }
        int total = 0;
        for (int count : dp.values()) {
            total = (total + count) % MOD;
        }
        return total;
    }
    
    private List<Integer> generateValidStates() {
        List<Integer> states = new ArrayList<>();
        backtrackGenerate(0, 0, -1, states);
        return states;
    }
    
    private void backtrackGenerate(int pos, int currentState, int lastColor, List<Integer> result) {
        if (pos == m) {
            result.add(currentState);
            return;
        }
        for (int color = 0; color < 3; color++) {
            if (color != lastColor) {
                backtrackGenerate(pos + 1, currentState * 3 + color, color, result);
            }
        }
    }
    
    private Map<Integer, List<Integer>> buildTransitions(List<Integer> states) {
        Map<Integer, List<Integer>> transitions = new HashMap<>();
        for (int state1 : states) {
            for (int state2 : states) {
                if (isValidTransition(state1, state2)) {
                    transitions.computeIfAbsent(state2, k -> new ArrayList<>()).add(state1);
                }
            }
        }
        return transitions;
    }
    
    private boolean isValidTransition(int state1, int state2) {
        for (int i = 0; i < m; i++) {
            if (state1 % 3 == state2 % 3) {
                return false;
            }
            state1 /= 3;
            state2 /= 3;
        }
        return true;
    }
}