WITH UserRank AS (
    SELECT
        name AS results,
        ROW_NUMBER() OVER (ORDER BY COUNT(*) DESC, name) AS user_rank
    FROM
        Users
        JOIN MovieRating USING (user_id)
    GROUP BY user_id
),
MovieRank AS (
    SELECT
        title AS results,
        ROW_NUMBER() OVER (ORDER BY AVG(rating) DESC, title) AS movie_rank
    FROM
        MovieRating
        JOIN Movies USING (movie_id)
    WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    GROUP BY movie_id
)
SELECT results
FROM UserRank
WHERE user_rank = 1
UNION ALL
SELECT results
FROM MovieRank
WHERE movie_rank = 1;