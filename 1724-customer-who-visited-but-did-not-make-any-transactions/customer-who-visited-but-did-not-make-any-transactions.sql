SELECT customer_id , COUNT(*) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions AS t on v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id