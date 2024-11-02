class Solution {
    private Map<String, String> parent;
    private Map<String, Double> weight;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        parent = new HashMap<>();
        weight = new HashMap<>();

        for (List<String> equation : equations) {
            parent.putIfAbsent(equation.get(0), equation.get(0));
            parent.putIfAbsent(equation.get(1), equation.get(1));
            weight.putIfAbsent(equation.get(0), 1.0);
            weight.putIfAbsent(equation.get(1), 1.0);
        }

        for (int i = 0; i < equations.size(); i++) {
            String var1 = equations.get(i).get(0);
            String var2 = equations.get(i).get(1);
            double value = values[i];

            union(var1, var2, value);
        }

        double[] result = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {
            String var1 = queries.get(i).get(0);
            String var2 = queries.get(i).get(1);

            if (!parent.containsKey(var1) || !parent.containsKey(var2) || !find(var1).equals(find(var2))) {
                result[i] = -1.0;
            } else {
                result[i] = weight.get(var1) / weight.get(var2);
            }
        }

        return result;
    }

    private void union(String var1, String var2, double value) {
        String root1 = find(var1);
        String root2 = find(var2);

        if (!root1.equals(root2)) {
            parent.put(root1, root2);
            weight.put(root1, weight.get(var2) * value / weight.get(var1));
        }
    }

    private String find(String var) {
        if (!var.equals(parent.get(var))) {
            String origin = parent.get(var);
            parent.put(var, find(origin));
            weight.put(var, weight.get(var) * weight.get(origin));
        }
        return parent.get(var);
    }
}