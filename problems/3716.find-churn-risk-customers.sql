-- @leetcode id=3716 questionId=4103 slug=find-churn-risk-customers lang=mysql site=leetcode.com title="Find Churn Risk Customers"
WITH user_stats AS (
    SELECT 
        user_id,
        MAX(CASE WHEN event_type != 'cancel' AND event_date = (
            SELECT MAX(event_date) FROM subscription_events s2 WHERE s2.user_id = s.user_id
        ) THEN plan_name END) AS current_plan,
        MAX(CASE WHEN event_type != 'cancel' AND event_date = (
            SELECT MAX(event_date) FROM subscription_events s2 WHERE s2.user_id = s.user_id
        ) THEN monthly_amount END) AS current_monthly_amount,
        MAX(monthly_amount) AS max_historical_amount,
        MAX(event_type) AS has_cancel_check,
        SUM(CASE WHEN event_type = 'downgrade' THEN 1 ELSE 0 END) AS downgrade_count,
        DATEDIFF(MAX(event_date), MIN(event_date)) AS days_as_subscriber,
        (SELECT event_type FROM subscription_events s3 
         WHERE s3.user_id = s.user_id 
         ORDER BY event_date DESC LIMIT 1) AS last_event_type
    FROM subscription_events s
    GROUP BY user_id
)
SELECT 
    user_id,
    current_plan,
    current_monthly_amount,
    max_historical_amount,
    days_as_subscriber
FROM user_stats
WHERE 
    last_event_type != 'cancel'
    AND downgrade_count >= 1
    AND current_monthly_amount < max_historical_amount * 0.5
    AND days_as_subscriber >= 60
ORDER BY days_as_subscriber DESC, user_id ASC;
