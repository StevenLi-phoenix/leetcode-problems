-- @leetcode id=3436 questionId=3782 slug=find-valid-emails lang=mysql site=leetcode.com title="Find Valid Emails"
# Write your MySQL query statement below
SELECT user_id, email
FROM Users
WHERE email REGEXP '^[A-Za-z0-9_]+@[A-Za-z]+\\.com$'
ORDER BY user_id;
