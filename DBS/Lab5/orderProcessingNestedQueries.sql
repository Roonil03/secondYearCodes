--i
select * from customer where city is null;

--ii
select c.cust#, c.cname, sum(o.ordamt) as total_purchase from customer c join orders o on c.cust# = o.cust# group by c.cust#, c.cname having sum(o.ordamt) = (
    select max(total_purchase)
    from (
        select sum(ordamt) as total_purchase
        from orders
        group by cust#
    )
);

--iii
select o.* from orders o where not exists (
    select 1
    from shipment s
    where s.order# = o.order#
);

--iv
select i.* from item i where not exists (
    select 1
    from order_items oi
    where oi.item# = i.item#
);

--v
select i.item#, i.unitprice, count(distinct o.cust#) as customer_count from item i join order_items oi on i.item# = oi.item# join orders o on oi.order# = o.order# group by i.item#, i.unitprice having count(distinct o.cust#) = (
    select max(customer_count)
    from (
        select count(distinct o2.cust#) as customer_count
        from order_items oi2
        join orders o2 on oi2.order# = o2.order#
        group by oi2.item#
    )
);

--vi
select o.* from orders o where o.order# not in (
    select order#
    from shipment
    where shipdate = to_date('2025-02-09', 'yyyy-mm-dd')
);

--vii
select distinct c.* from customer c where exists (
    select 1
    from orders o
    join shipment s on o.order# = s.order#
    where o.cust# = c.cust#
    and s.shipdate = to_date('2025-02-08', 'yyyy-mm-dd')
) and exists (
    select 1
    from orders o
    join shipment s on o.order# = s.order#
    where o.cust# = c.cust#
    and s.shipdate = to_date('2025-02-09', 'yyyy-mm-dd')
);

--viii
select c.* from customer c where 1 = (
    select count(distinct s.warehouse#)
    from orders o
    join shipment s on o.order# = s.order#
    where o.cust# = c.cust#
);

--ix
select c.cust#, c.cname, count(o.order#) as order_count from customer c join orders o on c.cust# = o.cust# group by c.cust#, c.cname having count(o.order#) = (
    select max(order_count)
    from (
        select count(order#) as order_count
        from orders
        group by cust#
    )
);