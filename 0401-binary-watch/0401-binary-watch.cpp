class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for (int mask = 0; mask < 1024; ++mask) {
            if (__builtin_popcount(mask) != turnedOn)
                continue;

            int hour = mask >> 6;
            int minute = mask & 63;

            if (hour < 12 && minute < 60) {
                string time = to_string(hour) + ":";
                if (minute < 10) time += '0';
                time += to_string(minute);
                res.push_back(time);
            }
        }

        return res;
    }
};