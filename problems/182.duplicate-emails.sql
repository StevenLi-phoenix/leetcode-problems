-- @leetcode id=182 questionId=182 slug=duplicate-emails lang=mysql site=leetcode.com title="Duplicate Emails"
# Write your MySQL query statement below
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;
