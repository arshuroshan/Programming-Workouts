SELECT
    e2.employee_id,
    e2.name,
    COUNT(e1.employee_id) AS reports_count,
    ROUND(AVG(e1.age)) AS average_age
FROM
    Employees AS e1
    RIGHT JOIN Employees AS e2 ON e1.reports_to = e2.employee_id
GROUP BY e2.employee_id, e2.name
HAVING COUNT(e1.employee_id) > 0
ORDER BY e2.employee_id;