-- @leetcode id=3586 questionId=3932 slug=find-covid-recovery-patients lang=mysql site=leetcode.com title="Find COVID Recovery Patients"
# Write your MySQL query statement below
WITH first_positive AS (
    SELECT patient_id, MIN(test_date) AS positive_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
first_negative_after AS (
    SELECT fp.patient_id, fp.positive_date, MIN(ct.test_date) AS negative_date
    FROM first_positive fp
    JOIN covid_tests ct
      ON ct.patient_id = fp.patient_id
     AND ct.result = 'Negative'
     AND ct.test_date > fp.positive_date
    GROUP BY fp.patient_id, fp.positive_date
)
SELECT
    p.patient_id,
    p.patient_name,
    p.age,
    DATEDIFF(fna.negative_date, fna.positive_date) AS recovery_time
FROM first_negative_after fna
JOIN patients p ON p.patient_id = fna.patient_id
ORDER BY recovery_time ASC, p.patient_name ASC;
