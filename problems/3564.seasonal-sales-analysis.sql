-- @leetcode id=3564 questionId=3898 slug=seasonal-sales-analysis lang=mysql site=leetcode.com title="Seasonal Sales Analysis"
# Write your MySQL query statement below
WITH seasoned AS (
    SELECT
        CASE
            WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            ELSE 'Fall'
        END AS season,
        p.category AS category,
        s.quantity AS quantity,
        s.quantity * s.price AS revenue
    FROM sales s
    JOIN products p ON s.product_id = p.product_id
),
agg AS (
    SELECT
        season,
        category,
        SUM(quantity) AS total_quantity,
        SUM(revenue) AS total_revenue
    FROM seasoned
    GROUP BY season, category
),
ranked AS (
    SELECT
        season,
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER (
            PARTITION BY season
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) AS rn
    FROM agg
)
SELECT season, category, total_quantity, total_revenue
FROM ranked
WHERE rn = 1
ORDER BY season ASC;
