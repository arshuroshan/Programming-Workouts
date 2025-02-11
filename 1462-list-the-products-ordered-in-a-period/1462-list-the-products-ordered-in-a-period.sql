SELECT
    product_name,
    unit
FROM (
    SELECT
        p.product_name,
        SUM(o.unit) AS unit
    FROM
        Orders AS o
        JOIN Products AS p ON o.product_id = p.product_id
    WHERE
        o.order_date >= '2020-02-01' AND o.order_date < '2020-03-01'
    GROUP BY
        o.product_id
) AS subquery
WHERE
    unit >= 100;