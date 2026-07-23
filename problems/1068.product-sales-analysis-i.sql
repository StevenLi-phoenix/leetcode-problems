-- @leetcode id=1068 questionId=1153 slug=product-sales-analysis-i lang=mysql site=leetcode.com title="Product Sales Analysis I"
# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales s
JOIN Product p ON s.product_id = p.product_id;
