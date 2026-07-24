-- @leetcode id=1757 questionId=1908 slug=recyclable-and-low-fat-products lang=mysql site=leetcode.com title="Recyclable and Low Fat Products"
# Write your MySQL query statement below
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';
