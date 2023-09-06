SELECT first_name, last_name, email, job_success_score
FROM Profiles
WHERE job_success_score >= 90 AND is_verified = 1
ORDER BY job_success_score DESC, first_name ASC, last_name ASC
    LIMIT 10;
