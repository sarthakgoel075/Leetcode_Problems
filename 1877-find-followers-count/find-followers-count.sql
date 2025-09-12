# Write your MySQL query statement below
select distinct(user_id),count(*)as followers_count from Followers group by user_id order by user_id