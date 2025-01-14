-- Write your MySQL query statement below
SELECT
    machine_id,
    ROUND(SUM(
        CASE
            WHEN activity_type = 'start' THEN -timestamp
            ELSE timestamp
        END
    ) / COUNT(*) * 2, 3) AS processing_time
FROM Activity
GROUP BY machine_id;