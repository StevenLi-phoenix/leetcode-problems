-- @leetcode id=3580 questionId=3921 slug=find-consistently-improving-employees lang=mysql site=leetcode.com title="Find Consistently Improving Employees"
WITH ranked AS (
    SELECT 
        employee_id,
        rating,
        review_date,
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rn
    FROM performance_reviews
),
last3 AS (
    SELECT employee_id, rating, rn
    FROM ranked
    WHERE rn <= 3
),
agg AS (
    SELECT 
        employee_id,
        COUNT(*) AS cnt,
        MAX(CASE WHEN rn = 1 THEN rating END) AS r1,
        MAX(CASE WHEN rn = 2 THEN rating END) AS r2,
        MAX(CASE WHEN rn = 3 THEN rating END) AS r3
    FROM last3
    GROUP BY employee_id
)
SELECT 
    e.employee_id,
    e.name,
    (a.r1 - a.r3) AS improvement_score
FROM agg a
JOIN employees e ON e.employee_id = a.employee_id
WHERE a.cnt = 3 AND a.r1 > a.r2 AND a.r2 > a.r3
ORDER BY improvement_score DESC, e.name ASC;
