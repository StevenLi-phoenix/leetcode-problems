-- @leetcode id=3611 questionId=3943 slug=find-overbooked-employees lang=mysql site=leetcode.com title="Find Overbooked Employees"
# Write your MySQL query statement below
SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    w.heavy_weeks AS meeting_heavy_weeks
FROM employees e
JOIN (
    SELECT
        employee_id,
        COUNT(*) AS heavy_weeks
    FROM (
        SELECT
            employee_id,
            DATE_SUB(meeting_date, INTERVAL WEEKDAY(meeting_date) DAY) AS week_start,
            SUM(duration_hours) AS total_hours
        FROM meetings
        GROUP BY employee_id, week_start
        HAVING total_hours > 20
    ) t
    GROUP BY employee_id
    HAVING COUNT(*) >= 2
) w ON e.employee_id = w.employee_id
ORDER BY w.heavy_weeks DESC, e.employee_name ASC;
