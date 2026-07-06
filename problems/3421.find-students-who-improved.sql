-- @leetcode id=3421 questionId=3767 slug=find-students-who-improved lang=mysql site=leetcode.com title="Find Students Who Improved"
# Write your MySQL query statement below
WITH ranked AS (
    SELECT
        student_id,
        subject,
        score,
        ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date ASC) AS rn_asc,
        ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date DESC) AS rn_desc,
        COUNT(*) OVER (PARTITION BY student_id, subject) AS exam_count
    FROM Scores
)
SELECT
    f.student_id,
    f.subject,
    f.score AS first_score,
    l.score AS latest_score
FROM ranked f
JOIN ranked l
  ON f.student_id = l.student_id
 AND f.subject = l.subject
WHERE f.rn_asc = 1
  AND l.rn_desc = 1
  AND f.exam_count >= 2
  AND l.score > f.score
ORDER BY f.student_id, f.subject;
