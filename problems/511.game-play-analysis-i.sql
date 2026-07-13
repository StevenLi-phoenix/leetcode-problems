-- @leetcode id=511 questionId=1179 slug=game-play-analysis-i lang=mysql site=leetcode.com title="Game Play Analysis I"
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
