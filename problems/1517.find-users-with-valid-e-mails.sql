-- @leetcode id=1517 questionId=1664 slug=find-users-with-valid-e-mails lang=mysql site=leetcode.com title="Find Users With Valid E-Mails"
# Write your MySQL query statement below
SELECT user_id, name, mail
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9._-]*@leetcode\.com$'
AND BINARY SUBSTRING_INDEX(mail, '@', -1) = 'leetcode.com';
