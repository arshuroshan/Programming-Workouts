class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            return day;
        };

        int aliceStart = convert(arriveAlice);
        int aliceEnd = convert(leaveAlice);
        int bobStart = convert(arriveBob);
        int bobEnd = convert(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return start <= end ? end - start + 1 : 0;
    }
};