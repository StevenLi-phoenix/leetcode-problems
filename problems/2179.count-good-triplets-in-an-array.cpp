// @leetcode id=2179 questionId=2280 slug=count-good-triplets-in-an-array lang=cpp site=leetcode.com title="Count Good Triplets in an Array"
class Solution {
public:
    vector<long long> bit;
    int bitN;

    void update(int pos, int delta) {
        for (pos++; pos <= bitN; pos += pos & (-pos)) bit[pos] += delta;
    }

    long long query(int pos) {
        if (pos < 0) return 0;
        long long res = 0;
        for (pos++; pos > 0; pos -= pos & (-pos)) res += bit[pos];
        return res;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = pos2[nums1[i]];

        bitN = n;
        bit.assign(n + 1, 0);
        vector<long long> left(n);
        for (int i = 0; i < n; i++) {
            left[i] = query(arr[i] - 1);
            update(arr[i], 1);
        }

        bit.assign(n + 1, 0);
        vector<long long> right(n);
        for (int i = n - 1; i >= 0; i--) {
            right[i] = query(n - 1) - query(arr[i]);
            update(arr[i], 1);
        }

        long long answer = 0;
        for (int i = 0; i < n; i++) answer += left[i] * right[i];

        return answer;
    }
};
