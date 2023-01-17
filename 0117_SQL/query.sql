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

-- customers who never order
select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);

-- delete duplicate email
DELETE p1 FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id

-- rising tem
select 
    b.Id 
from 
    weather a 
inner join 
    weather b 
where 
    DATEDIFF(b.recordDate,a.recordDate)=1 
and b.Temperature > a.Temperature;

-- game analysis
SELECT
    player_id,
    min(event_date) AS first_login
FROM
    Activity
GROUP BY
    player_id
;

-- find customer referee
select name
from Customer
where referee_id != 2 OR referee_id is null
;

-- customer with most order
SELECT
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1
;
