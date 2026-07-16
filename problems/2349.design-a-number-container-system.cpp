// @leetcode id=2349 questionId=2434 slug=design-a-number-container-system lang=cpp site=leetcode.com title="Design a Number Container System"
class NumberContainers {
public:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;

    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        auto it = numberToIndices.find(number);
        if (it == numberToIndices.end() || it->second.empty()) return -1;
        return *it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
