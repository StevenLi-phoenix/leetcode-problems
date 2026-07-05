// @leetcode id=2013 questionId=2139 slug=detect-squares lang=cpp site=leetcode.com title="Detect Squares"
class DetectSquares {
public:
    DetectSquares() {}

    void add(vector<int> point) {
        ++cnt[{point[0], point[1]}];
        colPoints[point[0]].insert(point[1]);
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int total = 0;
        auto it = colPoints.find(x);
        if (it == colPoints.end()) return 0;

        for (int y2 : it->second) {
            if (y2 == y) continue;
            int len = y2 - y;
            for (int dx : {len, -len}) {
                int x2 = x + dx;
                int c1 = getCount(x, y2);
                int c2 = getCount(x2, y);
                int c3 = getCount(x2, y2);
                total += c1 * c2 * c3;
            }
        }
        return total;
    }

private:
    map<pair<int, int>, int> cnt;
    unordered_map<int, unordered_set<int>> colPoints;

    int getCount(int x, int y) {
        auto it = cnt.find({x, y});
        return it != cnt.end() ? it->second : 0;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
