// @leetcode id=3321 questionId=3592 slug=find-x-sum-of-all-k-long-subarrays-ii lang=cpp site=leetcode.com title="Find X-Sum of All K-Long Subarrays II"
class Solution {
    public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<long long> ans;
    set<pair<int,int>> top, bot;
    long long topSum = 0;
    unordered_map<int,int> freq;
    auto removeElem = [&](int val, int f) {
    pair<int,int> p = {f, val};
    if (top.count(p)) {
    top.erase(p);
    topSum -= (long long)f * val;
    } else {
    bot.erase(p);
    }
    };
    auto addElem = [&](int val, int f) {
    pair<int,int> p = {f, val};
    if (!top.empty() && p >= *top.begin()) {
    top.insert(p);
    topSum += (long long)f * val;
    } else {
    bot.insert(p);
    }
    };
    auto balance = [&]() {
    while ((int)top.size() > x) {
    auto it = top.begin();
    topSum -= (long long)it->first * it->second;
    bot.insert(*it);
    top.erase(it);
    }
    while ((int)top.size() < x && !bot.empty()) {
    auto it = prev(bot.end());
    topSum += (long long)it->first * it->second;
    top.insert(*it);
    bot.erase(it);
    }
    };
    for (int i = 0; i < n; i++) {
    int val = nums[i];
    if (freq[val] > 0) removeElem(val, freq[val]);
    freq[val]++;
    addElem(val, freq[val]);
    if (i >= k) {
    int oval = nums[i - k];
    removeElem(oval, freq[oval]);
    freq[oval]--;
    if (freq[oval] > 0) addElem(oval, freq[oval]);
    }
    balance();
    if (i >= k - 1) ans.push_back(topSum);
    }
    return ans;
    }
    };
