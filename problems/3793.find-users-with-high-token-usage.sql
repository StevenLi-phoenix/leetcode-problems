-- @leetcode id=3793 questionId=4195 slug=find-users-with-high-token-usage lang=mysql site=leetcode.com title="Find Users with High Token Usage"
# Write your MySQL query statement below
SELECT
    user_id,
    COUNT(*) AS prompt_count,
    ROUND(AVG(tokens), 2) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING COUNT(*) >= 3 AND MAX(tokens) > AVG(tokens)
ORDER BY avg_tokens DESC, user_id ASC;
