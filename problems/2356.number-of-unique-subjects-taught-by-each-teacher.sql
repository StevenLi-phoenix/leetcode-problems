-- @leetcode id=2356 questionId=2495 slug=number-of-unique-subjects-taught-by-each-teacher lang=mysql site=leetcode.com title="Number of Unique Subjects Taught by Each Teacher"
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;
