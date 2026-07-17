// @leetcode id=2102 questionId=2207 slug=sequentially-ordinal-rank-tracker lang=cpp site=leetcode.com title="Sequentially Ordinal Rank Tracker"
class SORTracker {
public:
    set<pair<int,string>> top;
    set<pair<int,string>> rest;

    SORTracker() {
    }

    void add(string name, int score) {
        pair<int,string> key = {-score, name};
        rest.insert(key);

        if (!top.empty()) {
            auto worstTopIt = prev(top.end());
            if (key < *worstTopIt) {
                pair<int,string> worstTop = *worstTopIt;
                top.erase(worstTopIt);
                rest.erase(key);
                top.insert(key);
                rest.insert(worstTop);
            }
        }
    }

    string get() {
        auto it = rest.begin();
        pair<int,string> best = *it;
        rest.erase(it);
        top.insert(best);
        return best.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
