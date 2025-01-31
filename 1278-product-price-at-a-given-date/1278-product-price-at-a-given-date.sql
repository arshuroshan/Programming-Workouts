WITH
    LatestPrice AS (
        SELECT
            product_id,
            new_price AS price
        FROM Products
        WHERE (product_id, change_date) IN (
            SELECT
                product_id,
                MAX(change_date) AS change_date
            FROM Products
            WHERE change_date <= '2019-08-16'
            GROUP BY product_id
        )
    ),
    AllProducts AS (
        SELECT DISTINCT product_id
        FROM Products
    )
SELECT
    ap.product_id,
    IFNULL(lp.price, 10) AS price
FROM
    AllProducts ap
    LEFT JOIN LatestPrice lp
    ON ap.product_id = lp.product_id;