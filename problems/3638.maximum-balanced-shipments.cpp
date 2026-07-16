// @leetcode id=3638 questionId=3954 slug=maximum-balanced-shipments lang=cpp site=leetcode.com title="Maximum Balanced Shipments"
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count = 0;
        bool hasPending = false;
        int pendingMax = 0;
        for (int w : weight) {
            if (hasPending && w < pendingMax) {
                count++;
                hasPending = false;
            } else {
                pendingMax = hasPending ? max(pendingMax, w) : w;
                hasPending = true;
            }
        }
        return count;
    }
};
