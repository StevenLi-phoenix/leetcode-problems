-- @leetcode id=1873 questionId=2024 slug=calculate-special-bonus lang=mysql site=leetcode.com title="Calculate Special Bonus"
# Write your MySQL query statement below
SELECT
    employee_id,
    CASE
        WHEN employee_id % 2 = 1 AND name NOT LIKE 'M%' THEN salary
        ELSE 0
    END AS bonus
FROM Employees
ORDER BY employee_id;
