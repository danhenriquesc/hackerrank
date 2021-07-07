SELECT CONCAT(name, '(', UPPER(SUBSTRING(occupation,1,1)), ')') FROM occupations
ORDER BY name;
SELECT 'There are a total of ', COUNT(occupation), CONCAT(LOWER(occupation), 's.')
FROM occupations
GROUP BY occupation
ORDER BY COUNT(occupation), occupation;
