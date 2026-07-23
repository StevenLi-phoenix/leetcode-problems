-- @leetcode id=183 questionId=183 slug=customers-who-never-order lang=mysql site=leetcode.com title="Customers Who Never Order"
# Write your MySQL query statement below
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.id IS NULL;
