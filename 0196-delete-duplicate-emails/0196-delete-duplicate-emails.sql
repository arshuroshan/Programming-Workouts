DELETE FROM person
WHERE id IN (
    SELECT id FROM (
        SELECT p2.id
        FROM person p1
        JOIN person p2 ON p1.email = p2.email
        WHERE p1.id < p2.id
    ) AS duplicates
);