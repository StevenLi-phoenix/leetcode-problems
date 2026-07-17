-- @leetcode id=3482 questionId=3828 slug=analyze-organization-hierarchy lang=mysql site=leetcode.com title="Analyze Organization Hierarchy"
# Write your MySQL query statement below
WITH RECURSIVE levels AS (
    SELECT employee_id, employee_name, manager_id, 1 AS level
    FROM Employees
    WHERE manager_id IS NULL
    UNION ALL
    SELECT e.employee_id, e.employee_name, e.manager_id, l.level + 1
    FROM Employees e
    JOIN levels l ON e.manager_id = l.employee_id
),
descendants AS (
    SELECT employee_id AS ancestor_id, employee_id AS descendant_id, salary AS descendant_salary
    FROM Employees
    UNION ALL
    SELECT d.ancestor_id, e.employee_id, e.salary
    FROM descendants d
    JOIN Employees e ON e.manager_id = d.descendant_id
)
SELECT l.employee_id, l.employee_name, l.level,
       COUNT(d.descendant_id) - 1 AS team_size,
       SUM(d.descendant_salary) AS budget
FROM levels l
JOIN descendants d ON d.ancestor_id = l.employee_id
GROUP BY l.employee_id, l.employee_name, l.level
ORDER BY l.level ASC, budget DESC, l.employee_name ASC;
