-- @leetcode id=1693 questionId=1837 slug=daily-leads-and-partners lang=mysql site=leetcode.com title="Daily Leads and Partners"
# Write your MySQL query statement below
SELECT date_id, make_name,
       COUNT(DISTINCT lead_id) AS unique_leads,
       COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name;
