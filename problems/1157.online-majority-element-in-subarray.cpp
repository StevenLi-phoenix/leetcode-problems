// @leetcode id=1157 questionId=1262 slug=online-majority-element-in-subarray lang=cpp site=leetcode.com title="Online Majority Element In Subarray"
class MajorityChecker {
public:
    vector<int> a;
    unordered_map<int, vector<int>> positions;
    mt19937 rng;

    MajorityChecker(vector<int>& arr) : a(arr), rng(12345) {
        for (int i = 0; i < (int)arr.size(); i++) positions[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {
        uniform_int_distribution<int> dist(left, right);
        for (int t = 0; t < 25; t++) {
            int idx = dist(rng);
            int val = a[idx];
            auto& pos = positions[val];
            int cnt = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
            if (cnt >= threshold) return val;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
