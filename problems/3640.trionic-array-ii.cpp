// @leetcode id=3640 questionId=3956 slug=trionic-array-ii lang=cpp site=leetcode.com title="Trionic Array II"
class Solution {
    public:
    long long maxSumTrionic(vector<int>& nums) {
    int n = nums.size();
    const long long NEG_INF = LLONG_MIN / 2;
    long long up = NEG_INF, down = NEG_INF, up2 = NEG_INF;
    long long ans = NEG_INF;
    for (int i = 1; i < n; i++) {
    long long new_up2 = NEG_INF, new_down = NEG_INF, new_up = NEG_INF;
    if (nums[i] > nums[i-1]) {
    if (up != NEG_INF) new_up = max(new_up, up + nums[i]);
    new_up = max(new_up, (long long)nums[i-1] + nums[i]);
    if (down != NEG_INF) new_up2 = max(new_up2, down + nums[i]);
    if (up2 != NEG_INF) new_up2 = max(new_up2, up2 + nums[i]);
    }
    if (nums[i] < nums[i-1]) {
    if (up != NEG_INF) new_down = max(new_down, up + nums[i]);
    if (down != NEG_INF) new_down = max(new_down, down + nums[i]);
    }
    up = new_up;
    down = new_down;
    up2 = new_up2;
    if (up2 != NEG_INF) ans = max(ans, up2);
    }
    return ans;
    }
    };
