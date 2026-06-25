// @leetcode id=3318 questionId=3610 slug=find-x-sum-of-all-k-long-subarrays-i lang=cpp site=leetcode.com title="Find X-Sum of All K-Long Subarrays I"
class Solution {
    public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i <= n - k; i++) {
    map<int,int> freq;
    for (int j = i; j < i + k; j++) freq[nums[j]]++;
    vector<pair<int,int>> v;
    for (auto& [val, cnt] : freq) v.push_back({cnt, val});
    sort(v.rbegin(), v.rend());
    int sum = 0;
    for (int j = 0; j < min((int)v.size(), x); j++) sum += v[j].first * v[j].second;
    ans.push_back(sum);
    }
    return ans;
    }
    };
