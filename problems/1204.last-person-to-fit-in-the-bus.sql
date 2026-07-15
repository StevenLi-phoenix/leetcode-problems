-- @leetcode id=1204 questionId=1327 slug=last-person-to-fit-in-the-bus lang=mysql site=leetcode.com title="Last Person to Fit in the Bus"
# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name,
           SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM Queue
) t
WHERE running_weight <= 1000
ORDER BY running_weight DESC
LIMIT 1;
