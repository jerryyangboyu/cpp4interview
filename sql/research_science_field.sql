SELECT candidate_id,
        science_field,
        COUNT(*) AS total_victories_count
FROM Awards
GROUP BY candidate_id, science_field
        ORDER BY candidate_id, science_field;
