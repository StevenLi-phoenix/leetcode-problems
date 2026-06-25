-- @leetcode id=607 questionId=607 slug=sales-person lang=mysql site=leetcode.com title="Sales Person"
# Write your MySQL query statement below
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'RED'
);
