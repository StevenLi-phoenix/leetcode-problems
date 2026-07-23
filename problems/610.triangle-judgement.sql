-- @leetcode id=610 questionId=610 slug=triangle-judgement lang=mysql site=leetcode.com title="Triangle Judgement"
# Write your MySQL query statement below
SELECT x, y, z,
    CASE WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes' ELSE 'No' END AS triangle
FROM Triangle;
