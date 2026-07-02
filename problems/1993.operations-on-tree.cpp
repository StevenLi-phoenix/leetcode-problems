// @leetcode id=1993 questionId=2104 slug=operations-on-tree lang=cpp site=leetcode.com title="Operations on Tree"
class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();
        children.assign(n, {});
        lockedBy.assign(n, -1);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockedBy[num] != -1) return false;
        lockedBy[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockedBy[num] != user) return false;
        lockedBy[num] = -1;
        return true;
    }

    bool upgrade(int num, int user) {
        if (lockedBy[num] != -1) return false;

        int p = parent[num];
        while (p != -1) {
            if (lockedBy[p] != -1) return false;
            p = parent[p];
        }

        vector<int> descLocked;
        function<void(int)> dfs = [&](int node) {
            for (int c : children[node]) {
                if (lockedBy[c] != -1) descLocked.push_back(c);
                dfs(c);
            }
        };
        dfs(num);
        if (descLocked.empty()) return false;

        for (int d : descLocked) lockedBy[d] = -1;
        lockedBy[num] = user;
        return true;
    }

private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockedBy;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
