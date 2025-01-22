# Write your MySQL query statement below
SELECT ROUND(SUM(b.event_date IS NOT NULL) / COUNT(*), 2) AS fraction
FROM (
    SELECT player_id, MIN(event_date) AS event_date
    FROM Activity
    GROUP BY player_id
) AS a
LEFT JOIN Activity AS b
    ON a.player_id = b.player_id
    AND b.event_date = DATE_ADD(a.event_date, INTERVAL 1 DAY);