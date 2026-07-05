// @leetcode id=841 questionId=871 slug=keys-and-rooms lang=cpp site=leetcode.com title="Keys and Rooms"
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        vector<int> stack = {0};
        visited[0] = true;
        int count = 1;

        while (!stack.empty()) {
            int room = stack.back();
            stack.pop_back();
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    ++count;
                    stack.push_back(key);
                }
            }
        }
        return count == n;
    }
};
