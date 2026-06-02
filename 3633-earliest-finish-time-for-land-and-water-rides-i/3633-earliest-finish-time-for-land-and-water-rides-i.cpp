class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration),
                   solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }

private:
    int solve(vector<int>& startA, vector<int>& durA,
              vector<int>& startB, vector<int>& durB) {
        int firstDone = INT_MAX;

        for (int i = 0; i < startA.size(); i++) {
            firstDone = min(firstDone, startA[i] + durA[i]);
        }

        int best = INT_MAX;

        for (int i = 0; i < startB.size(); i++) {
            int beginSecond = firstDone > startB[i] ? firstDone : startB[i];
            best = min(best, beginSecond + durB[i]);
        }

        return best;
    }
};