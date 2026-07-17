// @leetcode id=1354 questionId=1479 slug=construct-target-array-with-multiple-sums lang=cpp site=leetcode.com title="Construct Target Array With Multiple Sums"
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target[0] == 1;

        priority_queue<long long> pq(target.begin(), target.end());
        long long sum = 0;
        for (int t : target) sum += t;

        while (pq.top() > 1) {
            long long largest = pq.top();
            pq.pop();
            long long rest = sum - largest;

            if (rest < 1) return false;
            if (largest <= rest) return false;

            long long prev;
            if (rest == 1) {
                prev = 1;
            } else {
                prev = largest % rest;
                if (prev == 0) prev = rest;
            }

            if (prev < 1) return false;

            sum = rest + prev;
            pq.push(prev);
        }

        return true;
    }
};
