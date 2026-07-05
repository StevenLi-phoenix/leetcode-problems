-- @leetcode id=1045 questionId=1135 slug=customers-who-bought-all-products lang=mysql site=leetcode.com title="Customers Who Bought All Products"
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);
