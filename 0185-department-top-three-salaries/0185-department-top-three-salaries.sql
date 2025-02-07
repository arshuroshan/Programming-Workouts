WITH RankedEmployees AS (
    SELECT
        e.NAME AS Employee,
        e.Salary,
        d.NAME AS Department,
        DENSE_RANK() OVER (PARTITION BY e.DepartmentId ORDER BY e.Salary DESC) AS SalaryRank
    FROM
        Employee e
    JOIN
        Department d ON e.DepartmentId = d.Id
)
SELECT
    Department,
    Employee,
    Salary
FROM
    RankedEmployees
WHERE
    SalaryRank <= 3;