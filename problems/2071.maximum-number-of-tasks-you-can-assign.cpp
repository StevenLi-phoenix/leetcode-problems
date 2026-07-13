// @leetcode id=2071 questionId=2180 slug=maximum-number-of-tasks-you-can-assign lang=cpp site=leetcode.com title="Maximum Number of Tasks You Can Assign"
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();

        auto canDo = [&](int k) -> bool {
            multiset<int> avail(workers.end() - k, workers.end());
            int pillsLeft = pills;
            for (int i = k - 1; i >= 0; i--) {
                int task = tasks[i];
                if (!avail.empty() && *avail.rbegin() >= task) {
                    avail.erase(prev(avail.end()));
                } else {
                    if (pillsLeft == 0) return false;
                    auto it = avail.lower_bound(task - strength);
                    if (it == avail.end()) return false;
                    avail.erase(it);
                    pillsLeft--;
                }
            }
            return true;
        };

        int lo = 0, hi = min(n, m), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canDo(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
