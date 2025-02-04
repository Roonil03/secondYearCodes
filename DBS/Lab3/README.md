# Lab Exercises:
1. Consider the insurance database given below:  
`PERSON (driver_id#: varchar(30), name: varchar(50), address:varchar(100)`  
`CAR (regno: varchar(20), model: varchar(30), Year:int)`  
`ACCIDENT (report_number: int, accd_date: date, location: varchar(50))`  
`OWNS (driver_id#: varchar(30), regno: varchar(20))`  
`PARTICIPATED (driver_id#: varchar(30), regno: varchar(20), report_number: int, damage_amount: int)`  
    - Create the above tables by properly specifying the primary keys and the foreign keys.
    - Enter at least five tuples for each relation. (Hint: Date format is ‘yyyy-mm-dd’)
    - Update the damage amount to 25000 for the car with a specific reg. no in a PARTICIPATED table with report number 12.
    - Delete the accident and related information that took place in a specific year. (Hint: Command to extract year component from the date attribute is, extract (year from accd_date) ) 
    - Alter table to add and delete an attribute.
    - Alter table to add Check constraint.

# Additional Exercises:
1. Consider the following relations for an order processing database application in a company.  
`CUSTOMER (cust#: int, cname: varchar(50), city: varchar(30))`  
`ORDERS (order#:int, odate: date, cust#: int, ordamt: int)`  
`ITEM (item#: int, unitprice: int)`  
`ORDER_ITEMS (order#:int, qty:int, item#:int)`  
`SHIPMENT (order#: int, warehouse#: int, shipdate: date)`  
`WAREHOUSE (warehouse#:int, city: varchar(30))`  

    - Create the above tables by properly specifying the primary keys and the foreign keys.
    - Enter at least five tuples for each relation.
    - Execute following queries on the database:
        - Produce a listing: CUSTNAME, No. of Orders, AVG_ORDER_AMT, where the middle column is the total number of orders by the customer and the last column is the average order amount for that customer.
        - List the order no for the orders that were shipped from all the warehouses that the company has in a specific city.
        - Decrease the order_amount by 10% if ordered quantity is greater than ten or else by 5% using Case construct.