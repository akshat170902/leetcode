# Write your MySQL query statement below
select c.name as Customers 
from Customers as c 
where id not in 
(
    select o.customerId
    from Orders as o
    where o.customerId=c.id
);