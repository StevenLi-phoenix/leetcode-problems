// @leetcode id=3761 questionId=4139 slug=minimum-absolute-distance-between-mirror-pairs lang=cpp site=leetcode.com title="Minimum Absolute Distance Between Mirror Pairs"
class Solution {
    public:
    int minMirrorPairDistance(vector<int>& nums) {
    auto rev = [](int x) {
    int r = 0;
    while (x > 0) {
    r = r * 10 + x % 10;
    x /= 10;
    }
    return r;
    };
    unordered_map<int, int> lastSeen;
    int res = INT_MAX;
    for (int j = 0; j < (int)nums.size(); j++) {
    if (lastSeen.count(nums[j])) {
    res = min(res, j - lastSeen[nums[j]]);
    }
    lastSeen[rev(nums[j])] = j;
    }
    return res == INT_MAX ? -1 : res;
    }
    };
