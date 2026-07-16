// @leetcode id=2241 questionId=2352 slug=design-an-atm-machine lang=cpp site=leetcode.com title="Design an ATM Machine"
class ATM {
public:
    ATM() : count(5, 0) {
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) count[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        int values[5] = {20, 50, 100, 200, 500};
        vector<long long> used(5, 0);
        long long remaining = amount;

        for (int i = 4; i >= 0; i--) {
            long long take = min((long long)count[i], remaining / values[i]);
            used[i] = take;
            remaining -= take * values[i];
        }

        if (remaining != 0) return {-1};

        for (int i = 0; i < 5; i++) count[i] -= used[i];
        return vector<int>(used.begin(), used.end());
    }

private:
    vector<long long> count;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
