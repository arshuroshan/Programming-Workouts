SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance i1
WHERE EXISTS (
    SELECT 1
    FROM Insurance i2
    WHERE i2.pid <> i1.pid
    AND i2.tiv_2015 = i1.tiv_2015
)
AND NOT EXISTS (
    SELECT 1
    FROM Insurance i3
    WHERE i3.pid <> i1.pid
    AND i3.lat = i1.lat
    AND i3.lon = i1.lon
);