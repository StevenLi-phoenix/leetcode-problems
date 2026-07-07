-- @leetcode id=185 questionId=185 slug=department-top-three-salaries lang=mysql site=leetcode.com title="Department Top Three Salaries"
# Write your MySQL query statement below
WITH ranked AS (
    SELECT
        e.name AS Employee,
        e.salary AS Salary,
        e.departmentId,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rnk
    FROM Employee e
)
SELECT d.name AS Department, r.Employee, r.Salary
FROM ranked r
JOIN Department d ON d.id = r.departmentId
WHERE r.rnk <= 3;
