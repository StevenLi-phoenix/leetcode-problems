-- @leetcode id=3465 questionId=3803 slug=find-products-with-valid-serial-numbers lang=mysql site=leetcode.com title="Find Products with Valid Serial Numbers"
# Write your MySQL query statement below
SELECT *
FROM products
WHERE REGEXP_LIKE(description, '(?<![A-Za-z0-9])SN[0-9]{4}-[0-9]{4}(?![A-Za-z0-9])', 'c')
ORDER BY product_id ASC;
