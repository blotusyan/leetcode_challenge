-- join two table 175
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId
;

-- employee earns more than manager 181
SELECT
    a.Name AS 'Employee'
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
        AND a.Salary > b.Salary
;

-- duplicate email
select Email from
(
  select Email, count(Email) as num
  from Person
  group by Email
) as statistic
where num > 1
;

select Email
from Person
group by Email
having count(Email)>1;


