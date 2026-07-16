-- @leetcode id=608 questionId=608 slug=tree-node lang=mysql site=leetcode.com title="Tree Node"
# Write your MySQL query statement below
SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;
