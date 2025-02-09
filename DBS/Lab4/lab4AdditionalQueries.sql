--a
select c.cname from customer c join orders o on c.cust# = o.cust# where o.odate = to_date('2015-09-05', 'yyyy-mm-dd');

--b
select order#, count(item#) as total_items from order_items group by order#;

--c
select order# from order_items group by order# order by count(item#) desc fetch first 1 rows only;

--d
select shipdate from shipment group by shipdate order by count(order#) desc fetch first 1 rows only;

--e
delete from item where item# = 1;

--f
select s.order# from shipment s join warehouse w on s.warehouse# = w.warehouse# where w.city = 'New York';

--g
select * from customer where cname like '%Smith'; 

--h
select c.cust#, c.cname, sum(o.ordamt) as total_order_amount from customer c join orders o on c.cust# = o.cust# group by c.cust#, c.cname order by total_order_amount desc;

--i
select c.cust#, c.cname from customer c join orders o on c.cust# = o.cust# join shipment s on o.order# = s.order# where s.shipdate = to_date('2025-01-06', 'yyyy-mm-dd') group by c.cust#, c.cname having count(o.order#) >= 3;