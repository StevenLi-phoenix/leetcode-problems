-- @leetcode id=1789 questionId=1942 slug=primary-department-for-each-employee lang=mysql site=leetcode.com title="Primary Department for Each Employee"
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
   OR employee_id IN (
       SELECT employee_id FROM Employee GROUP BY employee_id HAVING COUNT(*) = 1
   );
