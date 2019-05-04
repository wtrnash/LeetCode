# Write your MySQL query statement below
select 
    d.name as Department, 
    e.name as Employee, 
    e.Salary 
from Employee e, Department d 
where
    e.DepartmentId = d.id
    and
    (e.Salary, e.DepartmentId) in (select max(Salary), DepartmentId from Employee group by DepartmentId)
