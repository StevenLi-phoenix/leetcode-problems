// @leetcode id=1619 questionId=1210 slug=mean-of-array-after-removing-some-elements lang=cpp site=leetcode.com title="Mean of Array After Removing Some Elements"
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int cut = n / 20;
        long long sum = 0;
        for (int i = cut; i < n - cut; i++) sum += arr[i];
        return (double)sum / (n - 2 * cut);
    }
};
