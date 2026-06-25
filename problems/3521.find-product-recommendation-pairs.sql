-- @leetcode id=3521 questionId=3865 slug=find-product-recommendation-pairs lang=mysql site=leetcode.com title="Find Product Recommendation Pairs"
# Write your MySQL query statement below
SELECT 
    a.product_id AS product1_id,
    b.product_id AS product2_id,
    p1.category AS product1_category,
    p2.category AS product2_category,
    COUNT(DISTINCT a.user_id) AS customer_count
FROM ProductPurchases a
JOIN ProductPurchases b 
    ON a.user_id = b.user_id 
    AND a.product_id < b.product_id
JOIN ProductInfo p1 ON a.product_id = p1.product_id
JOIN ProductInfo p2 ON b.product_id = p2.product_id
GROUP BY a.product_id, b.product_id, p1.category, p2.category
HAVING COUNT(DISTINCT a.user_id) >= 3
ORDER BY customer_count DESC, product1_id ASC, product2_id ASC
