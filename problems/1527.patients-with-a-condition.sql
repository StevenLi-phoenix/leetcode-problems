-- @leetcode id=1527 questionId=1670 slug=patients-with-a-condition lang=mysql site=leetcode.com title="Patients With a Condition"
# Write your MySQL query statement below
SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%'
   OR conditions LIKE '% DIAB1%';
