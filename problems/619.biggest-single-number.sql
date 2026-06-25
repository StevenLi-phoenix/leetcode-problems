-- @leetcode id=619 questionId=619 slug=biggest-single-number lang=mysql site=leetcode.com title="Biggest Single Number"
SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
);
