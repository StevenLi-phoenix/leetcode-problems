-- @leetcode id=601 questionId=601 slug=human-traffic-of-stadium lang=mysql site=leetcode.com title="Human Traffic of Stadium"
# Write your MySQL query statement below
SELECT DISTINCT s1.id, s1.visit_date, s1.people
FROM Stadium s1, Stadium s2, Stadium s3
WHERE s1.people >= 100 AND s2.people >= 100 AND s3.people >= 100
  AND (
    (s1.id - s2.id = 1 AND s2.id - s3.id = 1)
    OR (s2.id - s1.id = 1 AND s1.id - s3.id = 1)
    OR (s1.id - s3.id = 1 AND s3.id - s2.id = 1)
    OR (s2.id - s1.id = 1 AND s3.id - s2.id = 1)
  )
ORDER BY visit_date;
