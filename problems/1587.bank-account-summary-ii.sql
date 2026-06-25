-- @leetcode id=1587 questionId=1734 slug=bank-account-summary-ii lang=mysql site=leetcode.com title="Bank Account Summary II"
SELECT u.name, SUM(t.amount) AS balance
FROM Users u
JOIN Transactions t ON u.account = t.account
GROUP BY u.account
HAVING SUM(t.amount) > 10000
