class Solution {
    struct Info {
        int product = 1;
        array<int, 5> count{};
    };

    int k, n;
    vector<Info> seg;

    Info combine(const Info& left, const Info& right) {
        Info res;
        res.product = left.product * right.product % k;
        res.count = left.count;

        for (int i = 0; i < k; ++i) {
            res.count[left.product * i % k] += right.count[i];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;
            seg[p].product = x;
            seg[p].count[x] = 1;
            return;
        }

        int m = l + (r - l) / 2;
        build(p * 2, l, m, nums);
        build(p * 2 + 1, m + 1, r, nums);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int value) {
        if (l == r) {
            seg[p] = Info();
            value %= k;
            seg[p].product = value;
            seg[p].count[value] = 1;
            return;
        }

        int m = l + (r - l) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, value);
        else
            update(p * 2 + 1, m + 1, r, idx, value);

        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }

    Info get(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int m = l + (r - l) / 2;

        if (qr <= m)
            return get(p * 2, l, m, ql, qr);

        if (ql > m)
            return get(p * 2 + 1, m + 1, r, ql, qr);

        return combine(
            get(p * 2, l, m, ql, qr),
            get(p * 2 + 1, m + 1, r, ql, qr)
        );
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();
        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            Info cur = get(1, 0, n - 1, q[2], n - 1);
            result.push_back(cur.count[q[3]]);
        }

        return result;
    }
};