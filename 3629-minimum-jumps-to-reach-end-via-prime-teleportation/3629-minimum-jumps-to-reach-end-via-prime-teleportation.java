class Solution {
    private static final int LIMIT = 1000001;
    private static final int[] spf = new int[LIMIT];

    static {
        for (int i = 2; i < LIMIT; i++) {
            if (spf[i] == 0) {
                for (int j = i; j < LIMIT; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    private List<Integer> primeFactors(int x) {
        List<Integer> res = new ArrayList<>();
        while (x > 1) {
            int p = spf[x];
            res.add(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        return res;
    }

    public int minJumps(int[] nums) {
        int n = nums.length;

        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int p : primeFactors(nums[i])) {
                map.computeIfAbsent(p, k -> new ArrayList<>()).add(i);
            }
        }

        Queue<Integer> q = new ArrayDeque<>();
        boolean[] seen = new boolean[n];

        q.offer(0);
        seen[0] = true;

        int step = 0;

        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                int cur = q.poll();

                if (cur == n - 1) {
                    return step;
                }

                if (cur + 1 < n && !seen[cur + 1]) {
                    seen[cur + 1] = true;
                    q.offer(cur + 1);
                }

                if (cur - 1 >= 0 && !seen[cur - 1]) {
                    seen[cur - 1] = true;
                    q.offer(cur - 1);
                }

                List<Integer> next = map.get(nums[cur]);

                if (next != null) {
                    for (int idx : next) {
                        if (!seen[idx]) {
                            seen[idx] = true;
                            q.offer(idx);
                        }
                    }
                    map.remove(nums[cur]);
                }
            }

            step++;
        }

        return -1;
    }
}