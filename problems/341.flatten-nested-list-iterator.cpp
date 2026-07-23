// @leetcode id=341 questionId=341 slug=flatten-nested-list-iterator lang=cpp site=leetcode.com title="Flatten Nested List Iterator"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> flat;
    int idx = 0;

    void flatten(const vector<NestedInteger> &list) {
        for (const auto &ni : list) {
            if (ni.isInteger()) {
                flat.push_back(ni);
            } else {
                flatten(ni.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        return flat[idx++].getInteger();
    }

    bool hasNext() {
        return idx < (int)flat.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
