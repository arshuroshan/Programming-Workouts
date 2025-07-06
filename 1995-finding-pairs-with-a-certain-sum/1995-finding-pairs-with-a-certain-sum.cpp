class FindSumPairs {
public:
    FindSumPairs(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        for (int x : b) cnt[x]++;
    }

    void add(int i, int v) {
        cnt[nums2[i]]--;
        nums2[i] += v;
        cnt[nums2[i]]++;
    }

    int count(int t) {
        int res = 0;
        for (int x : nums1) res += cnt[t - x];
        return res;
    }

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;
};
