# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p FROM Person as p,Person as c WHERE 
    p.id>c.id and p.Email=c.Email
    ;