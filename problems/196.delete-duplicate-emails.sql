-- @leetcode id=196 questionId=196 slug=delete-duplicate-emails lang=mysql site=leetcode.com title="Delete Duplicate Emails"
# Write your MySQL query statement below
DELETE p1 FROM Person p1
JOIN Person p2 ON p1.email = p2.email AND p1.id > p2.id;
