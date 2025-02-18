--1
create or replace function totalAccidents(year int) return int as 
    total int;
begin
    select count(*) into total from Accident where extract (year from accd_date) = year;
    return total;
end;
/

declare 
    result int;
begin
    result := totalAccidents(&year);
    dbms_output.put_line('Total Accidents are: ' || result);
end;
/

--2
create or replace procedure accdByDriver(name varchar, year int) as
    res int;
begin
    select sum(p.damage_amount) into res from participated p natural join accident a, Person p where p.name = name and (extract (year from a.accd_date)) = year;
    dbms_output.put_line('The sum is: ' || res);
end;
/

exec accdByDriver('Pythene', 2015);

--3
create or replace procedure accidentInformation(loc varchar) as
    cursor c1 is select report_number, accd_date, location from Accident where location = loc;
    f1 Accident.report_number%TYPE;    
    f2 Accident.accd_date%TYPE;
    f3 Accident.location%TYPE;
begin
    open c1;
    loop
        fetch c1 into f1, f2, f3;
        exit when c1%notfound;
        if c1%found then
            dbms_output.put_line('Report Number: ' || f1 || ', Date: ' || f2 || ', Location: ' || f3);
        end if;
    end loop;
    close c1;
end;
/

exec accidentInformation('Mumbai');

--4
declare
    cursor c1 is select p.name from Person p left join Participated pt on p.driver_id = pt.driver_id where pt.report_number is null;
    n Person.name%TYPE;    
begin
    open c1;
    dbms_output.put_line('People with no accidents:');
    loop
        fetch c1 into n;
        exit when c1%notfound;
        dbms_output.put_line(n);
    end loop;
    close c1;
end;
/

--5
create or replace function accidentsInvolved(license varchar) return int as
    total int;
begin
    select count(*) into total from Participated where license = accidentsInvolved.license;
    return total;
end;
/

declare 
    result int;
begin
    result := accidentsInvolved(&license);
    dbms_output.put_line('Total Accidents are: ' || result);
end;
/