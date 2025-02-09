insert into customer (cust#, cname, city) values (6, 'Frank', null);

insert into orders (order#, odate, cust#, ordamt) 
values (110, to_date('2025-02-09', 'yyyy-mm-dd'), 2, 1000);
insert into orders (order#, odate, cust#, ordamt) 
values (111, to_date('2025-02-09', 'yyyy-mm-dd'), 2, 1500);

insert into orders (order#, odate, cust#, ordamt) 
values (112, to_date('2025-02-09', 'yyyy-mm-dd'), 3, 800);

insert into item (item#, unitprice) values (6, 100);
insert into order_items (order#, qty, item#) values (110, 5, 2);
insert into order_items (order#, qty, item#) values (111, 3, 2);

insert into shipment (order#, warehouse#, shipdate) 
values (110, 1, to_date('2025-02-08', 'yyyy-mm-dd'));
insert into shipment (order#, warehouse#, shipdate) 
values (111, 1, to_date('2025-02-09', 'yyyy-mm-dd'));
