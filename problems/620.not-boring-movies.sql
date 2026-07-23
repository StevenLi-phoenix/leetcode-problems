-- @leetcode id=620 questionId=620 slug=not-boring-movies lang=mysql site=leetcode.com title="Not Boring Movies"
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE id % 2 = 1 AND description <> 'boring'
ORDER BY rating DESC;
