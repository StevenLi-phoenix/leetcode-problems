// @leetcode id=1705 questionId=1824 slug=maximum-number-of-eaten-apples lang=cpp site=leetcode.com title="Maximum Number of Eaten Apples"
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap; // {expiry, count}
        int eaten = 0;

        for (int day = 0; day < n || !heap.empty(); ++day) {
            if (day < n && apples[day] > 0) {
                heap.push({day + days[day], apples[day]});
            }
            while (!heap.empty() && heap.top().first <= day) {
                heap.pop();
            }
            if (!heap.empty()) {
                ++eaten;
                auto [expiry, count] = heap.top();
                heap.pop();
                if (count > 1) heap.push({expiry, count - 1});
            }
        }
        return eaten;
    }
};
