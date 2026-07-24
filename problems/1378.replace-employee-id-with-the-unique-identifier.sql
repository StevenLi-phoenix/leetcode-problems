-- @leetcode id=1378 questionId=1509 slug=replace-employee-id-with-the-unique-identifier lang=mysql site=leetcode.com title="Replace Employee ID With The Unique Identifier"
# Write your MySQL query statement below
SELECT u.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI u ON e.id = u.id;
