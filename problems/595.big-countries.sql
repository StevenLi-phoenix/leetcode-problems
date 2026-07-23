-- @leetcode id=595 questionId=595 slug=big-countries lang=mysql site=leetcode.com title="Big Countries"
# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;
