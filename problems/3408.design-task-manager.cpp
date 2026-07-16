// @leetcode id=3408 questionId=3678 slug=design-task-manager lang=cpp site=leetcode.com title="Design Task Manager"
class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) add(t[0], t[1], t[2]);
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        ordered.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto& [userId, oldPriority] = taskInfo[taskId];
        ordered.erase({oldPriority, taskId});
        oldPriority = newPriority;
        ordered.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        auto& [userId, priority] = taskInfo[taskId];
        ordered.erase({priority, taskId});
        taskInfo.erase(taskId);
    }

    int execTop() {
        if (ordered.empty()) return -1;
        auto it = ordered.rbegin();
        int taskId = it->second;
        int userId = taskInfo[taskId].first;
        ordered.erase(--ordered.end());
        taskInfo.erase(taskId);
        return userId;
    }

private:
    unordered_map<int, pair<int, int>> taskInfo; // taskId -> (userId, priority)
    set<pair<int, int>> ordered; // (priority, taskId)
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
