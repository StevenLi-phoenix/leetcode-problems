-- @leetcode id=1050 questionId=1136 slug=actors-and-directors-who-cooperated-at-least-three-times lang=mysql site=leetcode.com title="Actors and Directors Who Cooperated At Least Three Times"
# Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;
