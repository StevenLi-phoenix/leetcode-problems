-- @leetcode id=1211 questionId=1338 slug=queries-quality-and-percentage lang=mysql site=leetcode.com title="Queries Quality and Percentage"
# Write your MySQL query statement below
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(100 * AVG(rating < 3), 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;
