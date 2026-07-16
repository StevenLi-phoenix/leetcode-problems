-- @leetcode id=570 questionId=570 slug=managers-with-at-least-5-direct-reports lang=mysql site=leetcode.com title="Managers with at Least 5 Direct Reports"
# Write your MySQL query statement below
SELECT e.name AS name
FROM Employee e
WHERE e.id IN (
    SELECT managerId
    FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING COUNT(*) >= 5
);
