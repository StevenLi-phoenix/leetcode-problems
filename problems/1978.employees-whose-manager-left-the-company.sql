-- @leetcode id=1978 questionId=2127 slug=employees-whose-manager-left-the-company lang=mysql site=leetcode.com title="Employees Whose Manager Left the Company"
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE salary < 30000
  AND manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;
