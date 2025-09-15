# Write your MySQL query statement below
select p.product_name,sub.total_unit as unit from Products p join 
(select product_id,sum(unit) as total_unit from Orders where order_date between '2020-02-01' and '2020-02-29'  group by product_id having sum(unit)>=100)as sub on p.product_id=sub.product_id 