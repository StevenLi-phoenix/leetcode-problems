-- @leetcode id=1731 questionId=1882 slug=the-number-of-employees-which-report-to-each-employee lang=mysql site=leetcode.com title="The Number of Employees Which Report to Each Employee"
# Write your MySQL query statement below
SELECT
    m.employee_id,
    m.name,
    COUNT(e.employee_id) AS reports_count,
    ROUND(AVG(e.age)) AS average_age
FROM Employees m
JOIN Employees e ON e.reports_to = m.employee_id
GROUP BY m.employee_id, m.name
ORDER BY m.employee_id;
