-- @leetcode id=3808 questionId=4208 slug=find-emotionally-consistent-users lang=mysql site=leetcode.com title="Find Emotionally Consistent Users"
# Write your MySQL query statement below
WITH user_reaction_counts AS (
    SELECT
        user_id,
        reaction,
        COUNT(*) AS reaction_count
    FROM reactions
    GROUP BY user_id, reaction
),
user_totals AS (
    SELECT user_id, COUNT(*) AS total_reactions
    FROM reactions
    GROUP BY user_id
),
ranked AS (
    SELECT
        urc.user_id,
        urc.reaction,
        urc.reaction_count,
        ut.total_reactions,
        ROW_NUMBER() OVER (
            PARTITION BY urc.user_id
            ORDER BY urc.reaction_count DESC, urc.reaction ASC
        ) AS rn
    FROM user_reaction_counts urc
    JOIN user_totals ut ON urc.user_id = ut.user_id
)
SELECT
    user_id,
    reaction AS dominant_reaction,
    ROUND(reaction_count / total_reactions, 2) AS reaction_ratio
FROM ranked
WHERE rn = 1
    AND total_reactions >= 5
    AND reaction_count / total_reactions >= 0.6
ORDER BY reaction_ratio DESC, user_id ASC;
