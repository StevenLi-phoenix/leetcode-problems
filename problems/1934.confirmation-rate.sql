-- @leetcode id=1934 questionId=2087 slug=confirmation-rate lang=mysql site=leetcode.com title="Confirmation Rate"
# Write your MySQL query statement below
SELECT
    s.user_id,
    ROUND(
        COALESCE(AVG(c.action = 'confirmed'), 0),
        2
    ) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c ON s.user_id = c.user_id
GROUP BY s.user_id;
