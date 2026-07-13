-- @leetcode id=176 questionId=176 slug=second-highest-salary lang=mysql site=leetcode.com title="Second Highest Salary"
# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
