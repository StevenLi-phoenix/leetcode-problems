-- @leetcode id=3451 questionId=3792 slug=find-invalid-ip-addresses lang=mysql site=leetcode.com title="Find Invalid IP Addresses"
WITH parsed AS (
    SELECT
        ip,
        SUBSTRING_INDEX(ip, '.', 1) AS o1,
        SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 2), '.', -1) AS o2,
        SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 3), '.', -1) AS o3,
        SUBSTRING_INDEX(ip, '.', -1) AS o4,
        LENGTH(ip) - LENGTH(REPLACE(ip, '.', '')) AS dot_count
    FROM logs
),
invalid_check AS (
    SELECT
        ip,
        CASE WHEN dot_count != 3 THEN 1
             WHEN CAST(o1 AS UNSIGNED) > 255 OR (LENGTH(o1) > 1 AND LEFT(o1, 1) = '0') THEN 1
             WHEN CAST(o2 AS UNSIGNED) > 255 OR (LENGTH(o2) > 1 AND LEFT(o2, 1) = '0') THEN 1
             WHEN CAST(o3 AS UNSIGNED) > 255 OR (LENGTH(o3) > 1 AND LEFT(o3, 1) = '0') THEN 1
             WHEN CAST(o4 AS UNSIGNED) > 255 OR (LENGTH(o4) > 1 AND LEFT(o4, 1) = '0') THEN 1
             ELSE 0
        END AS is_invalid
    FROM parsed
)
SELECT ip, COUNT(*) AS invalid_count
FROM invalid_check
WHERE is_invalid = 1
GROUP BY ip
ORDER BY invalid_count DESC, ip DESC;
