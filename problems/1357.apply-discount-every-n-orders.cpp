// @leetcode id=1357 questionId=1459 slug=apply-discount-every-n-orders lang=cpp site=leetcode.com title="Apply Discount Every n Orders"
class Cashier {
private:
    int n;
    int discount;
    unordered_map<int, int> priceMap;
    int customerCount = 0;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for (size_t i = 0; i < products.size(); i++) {
            priceMap[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        customerCount++;
        double bill = 0;
        for (size_t i = 0; i < product.size(); i++) {
            bill += (double)amount[i] * priceMap[product[i]];
        }
        if (customerCount % n == 0) {
            bill *= (100.0 - discount) / 100.0;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
