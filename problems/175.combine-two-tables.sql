-- @leetcode id=175 questionId=175 slug=combine-two-tables lang=mysql site=leetcode.com title="Combine Two Tables"
# Write your MySQL query statement below
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
