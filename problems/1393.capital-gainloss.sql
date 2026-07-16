-- @leetcode id=1393 questionId=1523 slug=capital-gainloss lang=mysql site=leetcode.com title="Capital Gain/Loss"
# Write your MySQL query statement below
SELECT
    stock_name,
    SUM(CASE WHEN operation = 'Sell' THEN price ELSE -price END) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;
