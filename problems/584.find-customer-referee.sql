-- @leetcode id=584 questionId=584 slug=find-customer-referee lang=mysql site=leetcode.com title="Find Customer Referee"
SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL
