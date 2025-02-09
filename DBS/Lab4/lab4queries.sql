insert into Accident values (120, TO_DATE('2008-09-11', 'yyyy-mm-dd'), 'Udupi');

insert into Person values ('1010BM10', 'JaScript', 'Miku Diva');

insert into car values ('THE1010RE', 'Lamborgini Egoista', 2007, 'New');

update Car set type = 'Old' where model = 'Tesla Model 3';

update Car set type = 'New' where model  != 'Ford Mustang 2010';

update Car set type = 'Old' where model = 'Ford Mustang 2010';



select count(*) from accident where extract (year from accd_date) = '2008';



select count(*) from participated p natural join car c where c.model = 'Tesla Model 3';


select p.name as OWNER_NAME, count(pt.report_number) as No_of_Accidents, sum(pt.damage_amount) as total_damage_amt from Person p, participated pt where p.driver_id = pt.driver_id group by p.name order by sum(pt.damage_amount) desc;


insert into Accident values (617, '31-Jan-2008', 'Jkarata');

insert into participated values ('212WEAEE', 'THE1010RE', 111, 10384);

insert into participated values ('1233EKWA', 'P144B0T30', 919, 90122);

insert into participated values ('44300OOW', '1111WWWW0', 617, 19191);

select p.name as OWNER_NAME, TO_CHAR(a.accd_date, 'YYYY') AS ACCIDENT_YEAR, count(pt.report_number) as NO_OF_ACCIDENTS from Person p join Participated pt on p.driver_id = pt.driver_id join Accident a on pt.report_number = a.report_number group by p.name, TO_CHAR(a.accd_date, 'YYYY') having count(pt.report_number) > 2 order by ACCIDENT_YEAR, OWNER_NAME; 


select p.name as OWNER_NAME from Person p left join Participated pt on p.driver_id = pt.driver_id where pt.report_number is null;