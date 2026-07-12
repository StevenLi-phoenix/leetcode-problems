-- @leetcode id=1729 questionId=1877 slug=find-followers-count lang=mysql site=leetcode.com title="Find Followers Count"
# Write your MySQL query statement below
SELECT user_id, COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;
