--1
create or replace trigger abcd1 after insert on participated for each row 
declare
  v_acc_count number;
begin
  select count(distinct report_number)
  into v_acc_count
  from participated
  where driver_id = :new.driver_id;  
  if v_acc_count = 2 then
    dbms_output.put_line('Driver ' || :new.driver_id || ' has reached accident count 2.');
  end if;
end;
/

--2
select distinct p.driver_id from participated p where p.regno not in (
  select o.regno
  from owns o
  where o.driver_id = p.driver_id
);