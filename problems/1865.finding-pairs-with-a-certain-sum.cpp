// @leetcode id=1865 questionId=1995 slug=finding-pairs-with-a-certain-sum lang=cpp site=leetcode.com title="Finding Pairs With a Certain Sum"
class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) freq2[x]++;
    }

    void add(int index, int val) {
        freq2[n2[index]]--;
        n2[index] += val;
        freq2[n2[index]]++;
    }

    int count(int tot) {
        long long result = 0;
        for (int x : n1) {
            auto it = freq2.find(tot - x);
            if (it != freq2.end()) result += it->second;
        }
        return (int)result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
