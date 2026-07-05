// @leetcode id=2671 questionId=2778 slug=frequency-tracker lang=cpp site=leetcode.com title="Frequency Tracker"
class FrequencyTracker {
public:
    FrequencyTracker() {}

    void add(int number) {
        int& f = count[number];
        if (f > 0) --freqCount[f];
        ++f;
        ++freqCount[f];
    }

    void deleteOne(int number) {
        auto it = count.find(number);
        if (it == count.end() || it->second == 0) return;
        --freqCount[it->second];
        --it->second;
        if (it->second > 0) ++freqCount[it->second];
    }

    bool hasFrequency(int frequency) {
        auto it = freqCount.find(frequency);
        return it != freqCount.end() && it->second > 0;
    }

private:
    unordered_map<int, int> count;
    unordered_map<int, int> freqCount;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
