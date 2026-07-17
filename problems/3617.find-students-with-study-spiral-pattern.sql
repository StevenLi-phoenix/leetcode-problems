-- @leetcode id=3617 questionId=3961 slug=find-students-with-study-spiral-pattern lang=mysql site=leetcode.com title="Find Students with Study Spiral Pattern"
# Write your MySQL query statement below
WITH RECURSIVE ordered AS (
    SELECT s.student_id, s.subject, s.session_date, s.hours_studied,
           ROW_NUMBER() OVER (PARTITION BY s.student_id ORDER BY s.session_date) AS rn
    FROM study_sessions s
),
gaps AS (
    SELECT student_id, session_date,
           DATEDIFF(session_date, LAG(session_date) OVER (PARTITION BY student_id ORDER BY session_date)) AS gap_days
    FROM ordered
),
basestats AS (
    SELECT o.student_id,
           COUNT(*) AS total_sessions,
           SUM(o.hours_studied) AS total_hours,
           MAX(g.gap_days) AS max_gap
    FROM ordered o
    JOIN gaps g ON o.student_id = g.student_id AND o.session_date = g.session_date
    GROUP BY o.student_id
),
numbers AS (
    SELECT 3 AS n
    UNION ALL
    SELECT n + 1 FROM numbers WHERE n < 500
),
candidates AS (
    SELECT b.student_id, nu.n AS period
    FROM basestats b
    JOIN numbers nu ON nu.n <= b.total_sessions / 2 AND b.total_sessions % nu.n = 0
),
valid_periods AS (
    SELECT c.student_id, c.period,
           NOT EXISTS (
               SELECT 1 FROM ordered a
               JOIN ordered bb ON bb.student_id = a.student_id
                   AND CAST(bb.rn AS SIGNED) = CAST(a.rn AS SIGNED) - c.period
               WHERE a.student_id = c.student_id AND a.subject <> bb.subject
           ) AS is_valid
    FROM candidates c
),
best_period AS (
    SELECT student_id, MIN(period) AS cycle_length
    FROM valid_periods
    WHERE is_valid = 1
    GROUP BY student_id
)
SELECT bp.student_id, stu.student_name, stu.major, bp.cycle_length,
       b.total_hours AS total_study_hours
FROM best_period bp
JOIN basestats b ON b.student_id = bp.student_id
JOIN students stu ON stu.student_id = bp.student_id
WHERE (b.max_gap IS NULL OR b.max_gap <= 2)
ORDER BY bp.cycle_length DESC, b.total_hours DESC;
