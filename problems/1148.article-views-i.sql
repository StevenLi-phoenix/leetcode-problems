-- @leetcode id=1148 questionId=1258 slug=article-views-i lang=mysql site=leetcode.com title="Article Views I"
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
