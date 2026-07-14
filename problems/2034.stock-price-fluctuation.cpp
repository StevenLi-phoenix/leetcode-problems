// @leetcode id=2034 questionId=2161 slug=stock-price-fluctuation lang=cpp site=leetcode.com title="Stock Price Fluctuation "
class StockPrice {
public:
    unordered_map<int, int> priceAt;
    multiset<int> prices;
    int latestTime = 0;

    StockPrice() {
    }

    void update(int timestamp, int price) {
        auto it = priceAt.find(timestamp);
        if (it != priceAt.end()) {
            prices.erase(prices.find(it->second));
        }
        priceAt[timestamp] = price;
        prices.insert(price);
        latestTime = max(latestTime, timestamp);
    }

    int current() {
        return priceAt[latestTime];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
