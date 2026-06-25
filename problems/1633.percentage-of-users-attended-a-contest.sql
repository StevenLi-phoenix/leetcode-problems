-- @leetcode id=1633 questionId=1773 slug=percentage-of-users-attended-a-contest lang=mysql site=leetcode.com title="Percentage of Users Attended a Contest"
# Write your MySQL query statement below
SELECT 
    contest_id,
    ROUND(COUNT(user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC
