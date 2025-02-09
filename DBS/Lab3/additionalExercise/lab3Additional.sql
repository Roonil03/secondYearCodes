CREATE TABLE CUSTOMER (
    cust# INT PRIMARY KEY,
    cname VARCHAR(50),
    city VARCHAR(30)
);

CREATE TABLE ORDERS (
    order# INT PRIMARY KEY,
    odate DATE,
    cust# INT,
    ordamt INT,
    FOREIGN KEY (cust#) REFERENCES CUSTOMER(cust#)
);

CREATE TABLE ITEM (
    item# INT PRIMARY KEY,
    unitprice INT
);

CREATE TABLE ORDER_ITEMS (
    order# INT,
    qty INT,
    item# INT,
    PRIMARY KEY (order#, item#),
    FOREIGN KEY (order#) REFERENCES ORDERS(order#),
    FOREIGN KEY (item#) REFERENCES ITEM(item#)
);

CREATE TABLE SHIPMENT (
    order# INT,
    warehouse# INT,
    shipdate DATE,
    PRIMARY KEY (order#, warehouse#),
    FOREIGN KEY (order#) REFERENCES ORDERS(order#),
    FOREIGN KEY (warehouse#) REFERENCES WAREHOUSE(warehouse#)
);

CREATE TABLE WAREHOUSE (
    warehouse# INT PRIMARY KEY,
    city VARCHAR(30)
);


INSERT INTO CUSTOMER (cust#, cname, city) VALUES (1, 'Alice', 'New York');
INSERT INTO CUSTOMER (cust#, cname, city) VALUES (2, 'Bob', 'Los Angeles');
INSERT INTO CUSTOMER (cust#, cname, city) VALUES (3, 'Charlie', 'Chicago');
INSERT INTO CUSTOMER (cust#, cname, city) VALUES (4, 'Diana', 'Houston');
INSERT INTO CUSTOMER (cust#, cname, city) VALUES (5, 'Eve', 'Phoenix');

INSERT INTO WAREHOUSE (warehouse#, city) VALUES (1, 'New York');
INSERT INTO WAREHOUSE (warehouse#, city) VALUES (2, 'Los Angeles');
INSERT INTO WAREHOUSE (warehouse#, city) VALUES (3, 'Chicago');
INSERT INTO WAREHOUSE (warehouse#, city) VALUES (4, 'Houston');
INSERT INTO WAREHOUSE (warehouse#, city) VALUES (5, 'Phoenix');

INSERT INTO ORDERS (order#, odate, cust#, ordamt) VALUES (101, TO_DATE('2025-01-01', 'YYYY-MM-DD'), 1, 500);
INSERT INTO ORDERS (order#, odate, cust#, ordamt) VALUES (102, TO_DATE('2025-01-02', 'YYYY-MM-DD'), 2, 300);
INSERT INTO ORDERS (order#, odate, cust#, ordamt) VALUES (103, TO_DATE('2025-01-03', 'YYYY-MM-DD'), 3, 400);
INSERT INTO ORDERS (order#, odate, cust#, ordamt) VALUES (104, TO_DATE('2025-01-04', 'YYYY-MM-DD'), 4, 150);
INSERT INTO ORDERS (order#, odate, cust#, ordamt) VALUES (105, TO_DATE('2025-01-05', 'YYYY-MM-DD'), 5, 250);

INSERT INTO ITEM (item#, unitprice) VALUES (1, 50);
INSERT INTO ITEM (item#, unitprice) VALUES (2, 30);
INSERT INTO ITEM (item#, unitprice) VALUES (3, 20);
INSERT INTO ITEM (item#, unitprice) VALUES (4, 10);
INSERT INTO ITEM (item#, unitprice) VALUES (5, 60);

INSERT INTO ORDER_ITEMS (order#, qty, item#) VALUES (101, 5, 1);
INSERT INTO ORDER_ITEMS (order#, qty, item#) VALUES (102, 10, 2);
INSERT INTO ORDER_ITEMS (order#, qty, item#) VALUES (103, 15, 3);
INSERT INTO ORDER_ITEMS (order#, qty, item#) VALUES (104, 20, 4);
INSERT INTO ORDER_ITEMS (order#, qty, item#) VALUES (105, 25, 5);

INSERT INTO SHIPMENT (order#, warehouse#, shipdate) VALUES (101, 1, TO_DATE('2025-01-06', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT (order#, warehouse#, shipdate) VALUES (102, 2, TO_DATE('2025-01-07', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT (order#, warehouse#, shipdate) VALUES (103, 3, TO_DATE('2025-01-08', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT (order#, warehouse#, shipdate) VALUES (104, 4, TO_DATE('2025-01-09', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT (order#, warehouse#, shipdate) VALUES (105, 5, TO_DATE('2025-01-10', 'YYYY-MM-DD'));


-- a
SELECT c.cname AS CUSTNAME, COUNT(o.order#) AS No_of_Orders, AVG(o.ordamt) AS AVG_ORDER_AMT FROM CUSTOMER c JOIN ORDERS o ON c.cust# = o.cust# GROUP BY c.cname; 

--b
SELECT s.order# FROM SHIPMENT s JOIN WAREHOUSE w ON s.warehouse# = w.warehouse# WHERE w.city = 'New York'; 

--c
UPDATE ORDERS o
SET ordamt = ordamt * (CASE
    WHEN (SELECT qty FROM ORDER_ITEMS oi WHERE oi.order# = o.order#) > 10 THEN 0.9
    ELSE 0.95
END)
WHERE EXISTS (SELECT 1 FROM ORDER_ITEMS oi WHERE oi.order# = o.order#);