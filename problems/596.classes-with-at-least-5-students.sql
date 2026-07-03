-- @leetcode id=596 questionId=596 slug=classes-with-at-least-5-students lang=mysql site=leetcode.com title="Classes With at Least 5 Students"
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;
