-- @leetcode id=1890 questionId=2041 slug=the-latest-login-in-2020 lang=mysql site=leetcode.com title="The Latest Login in 2020"
# Write your MySQL query statement below
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY user_id;
