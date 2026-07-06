// @leetcode id=385 questionId=385 slug=mini-parser lang=cpp site=leetcode.com title="Mini Parser"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        vector<NestedInteger> stk;
        int i = 0;
        int n = s.size();

        while (i < n) {
            char c = s[i];
            if (c == '[') {
                stk.push_back(NestedInteger());
                ++i;
            } else if (c == ']') {
                NestedInteger top = stk.back();
                stk.pop_back();
                if (!stk.empty()) {
                    stk.back().add(top);
                } else {
                    return top;
                }
                ++i;
            } else if (c == ',') {
                ++i;
            } else {
                int start = i;
                if (s[i] == '-') ++i;
                while (i < n && isdigit(s[i])) ++i;
                int value = stoi(s.substr(start, i - start));
                stk.back().add(NestedInteger(value));
            }
        }

        return stk.back();
    }
};
