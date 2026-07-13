// @leetcode id=735 questionId=735 slug=asteroid-collision lang=cpp site=leetcode.com title="Asteroid Collision"
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && a < 0 && !st.empty() && st.back() > 0) {
                if (st.back() < -a) {
                    st.pop_back();
                } else if (st.back() == -a) {
                    st.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) st.push_back(a);
        }
        return st;
    }
};
