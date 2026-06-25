// @leetcode id=2751 questionId=2846 slug=robot-collisions lang=cpp site=leetcode.com title="Robot Collisions"
class Solution {
    public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){ return positions[a] < positions[b]; });
    stack<int> st;
    for (int i : idx) {
    if (directions[i] == 'R') {
    st.push(i);
    } else {
    while (!st.empty() && healths[i] > 0) {
    int top = st.top();
    if (healths[top] > healths[i]) {
    healths[top]--;
    healths[i] = 0;
    } else if (healths[top] < healths[i]) {
    healths[i]--;
    healths[top] = 0;
    st.pop();
    } else {
    healths[i] = 0;
    healths[top] = 0;
    st.pop();
    }
    }
    }
    }
    vector<int> result;
    for (int i = 0; i < n; i++) {
    if (healths[i] > 0) result.push_back(healths[i]);
    }
    return result;
    }
    };
