-- @leetcode id=627 questionId=627 slug=swap-sex-of-employees lang=mysql site=leetcode.com title="Swap Sex of Employees"
# Write your MySQL query statement below
UPDATE Salary
SET sex = IF(sex = 'm', 'f', 'm');
