--1

create or replace trigger abc1 after insert on participated for each row
declare
    driver_name varchar2(50);
    driver_address varchar2(100);
begin
    select name, address into driver_name, driver_address from person where driver_id = :new.driver_id;
    dbms_output.put_line('Driver id: ' || :new.driver_id || ', Name: ' || driver_name || ', Address: ' || driver_address);
end;
/

--2

alter table accident add total_damage number(10, 2);

create or replace trigger abc2
after insert or delete on participated
for each row
begin
    if inserting then
        update accident
        set total_damage = total_damage + :new.damage_amount
        where report_number = :new.report_number;
    elsif deleting then
        update accident
        set total_damage = total_damage - :old.damage_amount
        where report_number = :old.report_number;
    end if;
end;
/

update accident a
set total_damage = (
    select sum(p.damage_amount)
    from participated p
    where p.report_number = a.report_number
)
where exists (
    select 1
    from participated p
    where p.report_number = a.report_number
);

--3
declare
    amt number := 10000;
    cursor c1 is
        select p.regno, sum(p.damage_amount) as total_damage from participated p
        join accident a on p.report_number = a.report_number
        group by p.regno
        having sum(p.damage_amount) > amt;
    v_regno varchar2(20);
    v_total_damage number;

begin
    open c1;
    loop
        fetch c1 into v_regno, v_total_damage;
        exit when c1%NOTFOUND;
        dbms_output.put_line('Car Registration Number: ' || v_regno || ', Total Damage: ' || v_total_damage);
    end loop;
    close c1;
end;
/

--4
declare
    cursor c2 is
        select p.regno, sum(p.damage_amount) as total_damage
        from participated p
        group by p.regno
        having count(p.report_number) > 1;    
    v_regno varchar2(20);
    v_total_damage number;
begin
    open c2;    
    loop
        fetch c2 into v_regno, v_total_damage;
        exit when c2%NOTFOUND;
        dbms_output.put_line('Car Registration Number: ' || v_regno || ', Total Damage: ' || v_total_damage);
    end loop;    
    close c2;
end;
/

--5
select a.location, avg(p.damage_amount) as avg_damage from accident a join participated p on a.report_number = p.report_number group by a.location;



