insert into orders (order#, odate, cust#, ordamt) values (106, to_date('2015-09-05', 'yyyy-mm-dd'), 1, 600);

alter table order_items add constraint fk_item foreign key (item#) references item(item#) on delete cascade;

update customer set cname = 'Alice Smith' where cust# = 1;



insert into orders (order#, odate, cust#, ordamt) values (107, to_date('2025-01-01', 'yyyy-mm-dd'), 1, 700);
insert into orders (order#, odate, cust#, ordamt) values (108, to_date('2025-01-02', 'yyyy-mm-dd'), 1, 800);
insert into orders (order#, odate, cust#, ordamt) values (109, to_date('2025-01-03', 'yyyy-mm-dd'), 1, 900);

insert into shipment (order#, warehouse#, shipdate) values (107, 1, to_date('2025-01-06', 'yyyy-mm-dd'));
insert into shipment (order#, warehouse#, shipdate) values (108, 1, to_date('2025-01-06', 'yyyy-mm-dd'));
insert into shipment (order#, warehouse#, shipdate) values (109, 1, to_date('2025-01-06', 'yyyy-mm-dd'));

