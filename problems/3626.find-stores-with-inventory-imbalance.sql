-- @leetcode id=3626 questionId=3971 slug=find-stores-with-inventory-imbalance lang=mysql site=leetcode.com title="Find Stores with Inventory Imbalance"
# Write your MySQL query statement below
WITH ranked AS (
    SELECT
        store_id,
        product_name,
        quantity,
        price,
        ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price DESC) AS rn_high,
        ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price ASC) AS rn_low,
        COUNT(*) OVER (PARTITION BY store_id) AS product_count
    FROM inventory
),
high AS (
    SELECT store_id, product_name AS most_exp_product, quantity AS high_qty, product_count
    FROM ranked
    WHERE rn_high = 1
),
low AS (
    SELECT store_id, product_name AS cheapest_product, quantity AS low_qty
    FROM ranked
    WHERE rn_low = 1
)
SELECT
    s.store_id,
    s.store_name,
    s.location,
    h.most_exp_product,
    l.cheapest_product,
    ROUND(l.low_qty / h.high_qty, 2) AS imbalance_ratio
FROM stores s
JOIN high h ON s.store_id = h.store_id
JOIN low l ON s.store_id = l.store_id
WHERE h.product_count >= 3 AND h.high_qty < l.low_qty
ORDER BY imbalance_ratio DESC, s.store_name ASC;
