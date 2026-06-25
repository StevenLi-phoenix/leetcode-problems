// @leetcode id=1825 questionId=1953 slug=finding-mk-average lang=cpp site=leetcode.com title="Finding MK Average"
class MKAverage {
    int m, k;
    queue<int> q;
    multiset<int> lo, mid, hi;
    long long midSum;
    
    void removeFromSets(int val) {
        if (lo.count(val) && !lo.empty() && val <= *lo.rbegin()) {
            lo.erase(lo.find(val));
        } else if (hi.count(val) && !hi.empty() && val >= *hi.begin()) {
            hi.erase(hi.find(val));
        } else {
            mid.erase(mid.find(val));
            midSum -= val;
        }
    }
    
    void rebalance() {
        // lo should have exactly k elements
        // hi should have exactly k elements
        // mid should have the rest
        while ((int)lo.size() < k && !mid.empty()) {
            int v = *mid.begin();
            mid.erase(mid.begin());
            midSum -= v;
            lo.insert(v);
        }
        while ((int)lo.size() > k && !lo.empty()) {
            int v = *lo.rbegin();
            lo.erase(prev(lo.end()));
            mid.insert(v);
            midSum += v;
        }
        while ((int)hi.size() < k && !mid.empty()) {
            int v = *mid.rbegin();
            mid.erase(prev(mid.end()));
            midSum -= v;
            hi.insert(v);
        }
        while ((int)hi.size() > k && !hi.empty()) {
            int v = *hi.begin();
            hi.erase(hi.begin());
            mid.insert(v);
            midSum += v;
        }
        // fix ordering between lo, mid, hi
        while (!lo.empty() && !mid.empty() && *lo.rbegin() > *mid.begin()) {
            int lv = *lo.rbegin(); lo.erase(prev(lo.end()));
            int mv = *mid.begin(); mid.erase(mid.begin()); midSum -= mv;
            lo.insert(mv);
            mid.insert(lv); midSum += lv;
        }
        while (!hi.empty() && !mid.empty() && *hi.begin() < *mid.rbegin()) {
            int hv = *hi.begin(); hi.erase(hi.begin());
            int mv = *mid.rbegin(); mid.erase(prev(mid.end())); midSum -= mv;
            hi.insert(mv);
            mid.insert(hv); midSum += hv;
        }
    }
    
public:
    MKAverage(int m, int k) : m(m), k(k), midSum(0) {}
    
    void addElement(int num) {
        q.push(num);
        // Insert num into the right set
        if (lo.empty() || num <= *lo.rbegin()) {
            lo.insert(num);
        } else if (hi.empty() || num >= *hi.begin()) {
            hi.insert(num);
        } else {
            mid.insert(num);
            midSum += num;
        }
        
        if ((int)q.size() > m) {
            int old = q.front(); q.pop();
            removeFromSets(old);
        }
        
        rebalance();
    }
    
    int calculateMKAverage() {
        if ((int)q.size() < m) return -1;
        int midSize = m - 2 * k;
        if (midSize <= 0) return -1;
        return (int)(midSum / midSize);
    }
};
