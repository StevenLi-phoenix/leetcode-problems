-- @leetcode id=1667 questionId=1811 slug=fix-names-in-a-table lang=mysql site=leetcode.com title="Fix Names in a Table"
SELECT user_id, CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;
