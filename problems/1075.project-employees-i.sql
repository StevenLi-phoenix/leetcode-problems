-- @leetcode id=1075 questionId=1161 slug=project-employees-i lang=mysql site=leetcode.com title="Project Employees I"
# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years
FROM Project p
JOIN Employee e ON p.employee_id = e.employee_id
GROUP BY p.project_id;
