// @leetcode id=307 questionId=307 slug=range-sum-query-mutable lang=cpp site=leetcode.com title="Range Sum Query - Mutable"
class NumArray {
public:
    int n;
    vector<int> nums;
    vector<int> tree;

    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) add(i, nums[i]);
    }

    void add(int i, int delta) {
        for (i++; i <= n; i += i & (-i)) tree[i] += delta;
    }

    int prefixSum(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & (-i)) sum += tree[i];
        return sum;
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - (left > 0 ? prefixSum(left - 1) : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
