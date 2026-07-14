// @leetcode id=901 questionId=937 slug=online-stock-span lang=cpp site=leetcode.com title="Online Stock Span"
class StockSpanner {
public:
    vector<pair<int, int>> stack;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        while (!stack.empty() && stack.back().first <= price) {
            span += stack.back().second;
            stack.pop_back();
        }
        stack.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
