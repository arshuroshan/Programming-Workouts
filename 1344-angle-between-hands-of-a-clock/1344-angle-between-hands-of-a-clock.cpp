class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12 + minutes / 60.0) * 30.0;
        double minuteAngle = minutes * 6.0;

        double angle = fabs(hourAngle - minuteAngle);
        return angle > 180.0 ? 360.0 - angle : angle;
    }
};