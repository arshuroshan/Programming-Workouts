SELECT
    id,
    CASE
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN student
        WHEN id % 2 = 1 THEN (SELECT student FROM Seat WHERE id = s1.id + 1)
        ELSE (SELECT student FROM Seat WHERE id = s1.id - 1)
    END AS student
FROM
    Seat AS s1
ORDER BY
    id;