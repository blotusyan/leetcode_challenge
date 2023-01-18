-- DDL
Create table If Not Exists cinema (id int, movie varchar(255), description varchar(255), rating float(2, 1))
Truncate table cinema
insert into cinema (id, movie, description, rating) values ('1', 'War', 'great 3D', '8.9')
insert into cinema (id, movie, description, rating) values ('2', 'Science', 'fiction', '8.5')
insert into cinema (id, movie, description, rating) values ('3', 'irish', 'boring', '6.2')
insert into cinema (id, movie, description, rating) values ('4', 'Ice song', 'Fantacy', '8.6')
insert into cinema (id, movie, description, rating) values ('5', 'House card', 'Interesting', '9.1')

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

-- sales person no order with red
SELECT
    s.name
FROM
    salesperson s
WHERE
    s.sales_id NOT IN (SELECT
            o.sales_id
        FROM
            orders o
                LEFT JOIN
            company c ON o.com_id = c.com_id
        WHERE
            c.name = 'RED')
;

-- swap sex
UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;

-- second high
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;

-- rank score
select a.Score as Score,
(
    select count(distinct b.Score) 
    from Scores b 
    where b.Score >= a.Score
) as 'rank'
from Scores a
order by a.Score DESC
;