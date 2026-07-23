-- @leetcode id=1741 questionId=1892 slug=find-total-time-spent-by-each-employee lang=mysql site=leetcode.com title="Find Total Time Spent by Each Employee"
# Write your MySQL query statement below
SELECT event_day AS day, emp_id, SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY event_day, emp_id;
