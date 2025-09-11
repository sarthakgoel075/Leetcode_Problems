# Write your MySQL query statement below
select a.name,b.unique_id from employees as a left join  EmployeeUNI as b using (id)