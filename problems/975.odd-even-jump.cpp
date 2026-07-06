// @leetcode id=975 questionId=1017 slug=odd-even-jump lang=cpp site=leetcode.com title="Odd Even Jump"
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> ascOrder(n), descOrder(n);
        iota(ascOrder.begin(), ascOrder.end(), 0);
        iota(descOrder.begin(), descOrder.end(), 0);

        sort(ascOrder.begin(), ascOrder.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] < arr[b];
            return a < b;
        });
        sort(descOrder.begin(), descOrder.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] > arr[b];
            return a < b;
        });

        vector<int> oddNext = buildNext(ascOrder, n);
        vector<int> evenNext = buildNext(descOrder, n);

        vector<bool> canOdd(n, false), canEven(n, false);
        canOdd[n - 1] = canEven[n - 1] = true;

        int count = 1;
        for (int i = n - 2; i >= 0; --i) {
            canOdd[i] = oddNext[i] != -1 && canEven[oddNext[i]];
            canEven[i] = evenNext[i] != -1 && canOdd[evenNext[i]];
            if (canOdd[i]) ++count;
        }
        return count;
    }

private:
    vector<int> buildNext(vector<int>& order, int n) {
        vector<int> next(n, -1);
        vector<int> stk;
        for (int i : order) {
            while (!stk.empty() && stk.back() < i) {
                next[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return next;
    }
};
