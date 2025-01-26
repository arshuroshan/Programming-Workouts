# Write your MySQL query statement below
SELECT class
FROM Courses
WHERE (SELECT COUNT(*) FROM Courses c2 WHERE c2.class = Courses.class) >= 5
GROUP BY class;