# Write your MySQL query statement below
select max(num) as num from MyNumbers where num IN (select num as num from MyNumbers group by num having count(num)=1)