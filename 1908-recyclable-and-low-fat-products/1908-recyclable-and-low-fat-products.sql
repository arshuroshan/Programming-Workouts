SELECT product_id
FROM (
    SELECT product_id, low_fats, recyclable
    FROM Products
) AS subquery
WHERE low_fats = 'Y' AND recyclable = 'Y';