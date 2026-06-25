-- @leetcode id=180 questionId=180 slug=consecutive-numbers lang=mysql site=leetcode.com title="Consecutive Numbers"
# Write your MySQL query statement below
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.id + 1 = l2.id AND l1.num = l2.num
JOIN Logs l3 ON l1.id + 2 = l3.id AND l1.num = l3.num;
