### Higher than 75 Marks

```
select name from students where marks>75 order by right(name,3) asc, id asc
```

This query returns the names (selects the name attribute) of all students from the *student* relation whose marks are greater than 75, sorted according to the last 3 characters of the student name and id, in ascending order.
