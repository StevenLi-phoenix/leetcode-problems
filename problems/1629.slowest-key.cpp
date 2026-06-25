// @leetcode id=1629 questionId=1751 slug=slowest-key lang=cpp site=leetcode.com title="Slowest Key"
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxDuration = releaseTimes[0];
        char result = keysPressed[0];

        for (int i = 1; i < keysPressed.length(); i++) {
            int duration = releaseTimes[i] - releaseTimes[i-1];
            if (duration > maxDuration || (duration == maxDuration && keysPressed[i] > result)) {
                maxDuration = duration;
                result = keysPressed[i];
            }
        }

        return result;
    }
};
