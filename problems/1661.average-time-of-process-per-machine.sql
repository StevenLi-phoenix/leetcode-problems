-- @leetcode id=1661 questionId=1801 slug=average-time-of-process-per-machine lang=mysql site=leetcode.com title="Average Time of Process per Machine"
# Write your MySQL query statement below
SELECT
    s.machine_id,
    ROUND(AVG(e.timestamp - s.timestamp), 3) AS processing_time
FROM Activity s
JOIN Activity e
    ON s.machine_id = e.machine_id
    AND s.process_id = e.process_id
    AND s.activity_type = 'start'
    AND e.activity_type = 'end'
GROUP BY s.machine_id;
