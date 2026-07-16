-- @leetcode id=626 questionId=626 slug=exchange-seats lang=mysql site=leetcode.com title="Exchange Seats"
# Write your MySQL query statement below
SELECT
    CASE
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id
        WHEN id % 2 = 1 THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id;
