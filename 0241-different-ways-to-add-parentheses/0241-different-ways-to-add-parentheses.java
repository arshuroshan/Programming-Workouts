import java.util.*;

class Solution {
    private static Map<String, List<Integer>> memo = new HashMap<>();

    public List<Integer> diffWaysToCompute(String expression) {
        return compute(expression);
    }

    private List<Integer> compute(String exp) {
        if (memo.containsKey(exp)) {
            return memo.get(exp);
        }
        List<Integer> results = new ArrayList<>();
        if (exp.length() < 3) {
            results.add(Integer.parseInt(exp));
            return results;
        }
        
        for (int i = 0; i < exp.length(); i++) {
            char c = exp.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                String leftExp = exp.substring(0, i);
                String rightExp = exp.substring(i + 1);

                List<Integer> leftResults = compute(leftExp);
                List<Integer> rightResults = compute(rightExp);
                
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        switch (c) {
                            case '-':
                                results.add(left - right);
                                break;
                            case '+':
                                results.add(left + right);
                                break;
                            case '*':
                                results.add(left * right);
                                break;
                        }
                    }
                }
            }
        }
        memo.put(exp, results);
        return results;
    }
}