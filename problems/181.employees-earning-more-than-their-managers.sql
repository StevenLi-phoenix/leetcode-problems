-- @leetcode id=181 questionId=181 slug=employees-earning-more-than-their-managers lang=mysql site=leetcode.com title="Employees Earning More Than Their Managers"
# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m ON e.managerId = m.id
WHERE e.salary > m.salary;
