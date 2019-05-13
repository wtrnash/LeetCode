# Write your MySQL query statement below
select w.Id from Weather w 
where
    w.Temperature > (select Temperature from Weather where DATEDIFF(RecordDate, w.RecordDate) = -1)