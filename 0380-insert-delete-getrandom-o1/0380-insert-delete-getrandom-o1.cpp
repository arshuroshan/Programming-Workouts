class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (d.count(val)) {
            return false;
        }
        d[val] = q.size();
        q.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!d.count(val)) {
            return false;
        }
        int lastIndex = q.size() - 1;
        int valIndex = d[val];

        swap(q[valIndex], q[lastIndex]);
        d[q[valIndex]] = valIndex;

        q.pop_back();
        d.erase(val);
        return true;
    }

    int getRandom() {
        return q[rand() % q.size()];
    }

private:
    unordered_map<int, int> d;
    vector<int> q;
};