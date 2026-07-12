-- @leetcode id=1070 questionId=1155 slug=product-sales-analysis-iii lang=mysql site=leetcode.com title="Product Sales Analysis III"
# Write your MySQL query statement below
SELECT s.product_id, s.year AS first_year, s.quantity, s.price
FROM Sales s
JOIN (
    SELECT product_id, MIN(year) AS min_year
    FROM Sales
    GROUP BY product_id
) fy ON s.product_id = fy.product_id AND s.year = fy.min_year;
