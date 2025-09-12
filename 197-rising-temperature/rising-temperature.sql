select w2.id from weather w1 join weather w2 on
DATEDIFF(w2.recordDate,w1.recordDate)=1 
where w1.temperature<w2.temperature