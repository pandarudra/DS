SELECT en.unique_id , e.name from 
Employees e left join EmployeeUNI en
ON e.id = en.id 