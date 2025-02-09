Lab Exercises:
1. Consider the following database of student enrollment in courses and books adopted for each course  
`STUDENT (regno: varchar(20), name: varchar(50), major: varchar(20), bdate:date)`  
`COURSE (course#:int, cname: varchar(30), dept: varchar(30))`  
`ENROLL (regno: varchar(20), course#:int, sem:int, book_isbn:int)`  
`BOOK_ADOPTION (course#:int, sem:int, book_isbn:int)`  
`TEXT (book_isbn:int, booktitle: varchar(50), publisher: varchar(50), author: varchar(50))`  
    - Create the above tables by properly specifying the primary keys and the foreign keys.
    - Enter at least five tuples for each relation.
    - Execute following queries on the database using nested subquery concept:
        - List the courses which uses more than 1 text book.
        - List the departments whose all course text books are published by a particular publisher.
        - Find the students who have enrolled for course of more than one department
        - Produce a list of students who are not enrolled.
        - List the department which adopts all the books from the particular publisher.
        - List the books which are adopted by the course as well as enrolled by the student.
        - List the courses which has adapted at least two books from a specific publisher.
        - Identify the students who are enrolled for maximum number of books.
        - List the publishers along with the number of books published by them.
        - List the students who enrolled for all the books adopted by their course.

# Additional Exercises:
For the order processing database demonstrate using nested subquery how you
1. Find the customers whose address is not known yet.
2. Find the customer who has made a maximum purchase till date.
3. Display all those orders which have not been shipped yet.
4. Select all those items which have not been bought by any customer.
5. Find the item which has been bought by most of the customers.
6. List the orders which are not shipped on a particular date.
7. Identify the customers whose orders are shipped on a both specified days.
8. Give the customer information whose all orders are shipped from a single warehouse.
9. List the customers with maximum number of orders.