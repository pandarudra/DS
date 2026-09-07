select w.id from 
Weather w join Weather x 
on DATEDIFF(w.recordDate , x.recordDate) = 1 
where (w.temperature  > x.temperature)