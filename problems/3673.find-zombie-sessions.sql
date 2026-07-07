-- @leetcode id=3673 questionId=4043 slug=find-zombie-sessions lang=mysql site=leetcode.com title="Find Zombie Sessions"
# Write your MySQL query statement below
SELECT
    session_id,
    ANY_VALUE(user_id) AS user_id,
    TIMESTAMPDIFF(MINUTE, MIN(event_timestamp), MAX(event_timestamp)) AS session_duration_minutes,
    COUNT(CASE WHEN event_type = 'scroll' THEN 1 END) AS scroll_count
FROM app_events
GROUP BY session_id
HAVING session_duration_minutes > 30
   AND scroll_count >= 5
   AND COUNT(CASE WHEN event_type = 'click' THEN 1 END) / scroll_count < 0.20
   AND COUNT(CASE WHEN event_type = 'purchase' THEN 1 END) = 0
ORDER BY scroll_count DESC, session_id ASC;
