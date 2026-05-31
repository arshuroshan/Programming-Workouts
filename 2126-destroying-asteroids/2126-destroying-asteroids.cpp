class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long current = mass;
        int i = 0, n = asteroids.size();

        while (i < n) {
            if (current < asteroids[i]) return false;
            current += asteroids[i++];
        }

        return true;
    }
};