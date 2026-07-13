// @leetcode id=690 questionId=690 slug=employee-importance lang=cpp site=leetcode.com title="Employee Importance"
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> byId;
        for (auto* e : employees) byId[e->id] = e;

        int total = 0;
        vector<int> stack = {id};
        while (!stack.empty()) {
            int cur = stack.back();
            stack.pop_back();
            Employee* e = byId[cur];
            total += e->importance;
            for (int sub : e->subordinates) stack.push_back(sub);
        }
        return total;
    }
};
