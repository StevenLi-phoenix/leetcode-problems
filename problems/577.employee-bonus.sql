-- @leetcode id=577 questionId=577 slug=employee-bonus lang=mysql site=leetcode.com title="Employee Bonus"
# Write your MySQL query statement below
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b ON e.empId = b.empId
WHERE b.bonus IS NULL OR b.bonus < 1000;
