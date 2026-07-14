// @leetcode id=1352 questionId=1477 slug=product-of-the-last-k-numbers lang=cpp site=leetcode.com title="Product of the Last K Numbers"
class ProductOfNumbers {
public:
    vector<long long> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size() - 1;
        if (k > n) return 0;
        return (int)(prefix[n] / prefix[n - k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
