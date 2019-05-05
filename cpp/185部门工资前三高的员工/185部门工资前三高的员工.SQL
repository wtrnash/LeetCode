# Write your MySQL query statement below
select 
    d.Name as Department, e.Name as Employee, e.Salary as Salary
from 
    Employee as e inner join Department as d on e.DepartmentId = d.Id
where
     (select count(distinct Salary) from Employee where Salary > e.Salary and 
     Departmentid = e.Departmentid) < 3 order by e.departmentid, Salary desc
    