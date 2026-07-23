-- @leetcode id=1407 questionId=1541 slug=top-travellers lang=mysql site=leetcode.com title="Top Travellers"
# Write your MySQL query statement below
SELECT u.name, COALESCE(SUM(r.distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY travelled_distance DESC, u.name ASC;
