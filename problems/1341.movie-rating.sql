-- @leetcode id=1341 questionId=1480 slug=movie-rating lang=mysql site=leetcode.com title="Movie Rating"
# Write your MySQL query statement below
(
    SELECT u.name AS results
    FROM MovieRating mr
    JOIN Users u ON u.user_id = mr.user_id
    GROUP BY mr.user_id
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT m.title AS results
    FROM MovieRating mr
    JOIN Movies m ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01' AND mr.created_at < '2020-03-01'
    GROUP BY mr.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
);
