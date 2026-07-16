-- @leetcode id=178 questionId=178 slug=rank-scores lang=mysql site=leetcode.com title="Rank Scores"
# Write your MySQL query statement below
SELECT
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM Scores
ORDER BY score DESC;
