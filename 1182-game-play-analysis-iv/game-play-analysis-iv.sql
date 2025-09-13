# Write your MySQL query statement below
select round(count(distinct player_id)/(select count(distinct player_id) from Activity),2) as fraction from Activity
where (player_id,date_sub(event_date,interval 1 day))IN
(select player_id,MIN(event_date) as min_date from Activity group by player_id)