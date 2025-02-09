create table Student(
    regno varchar(20),
    name varchar(20),
    major varchar(20),
    bdate date,
    primary key (regno)
);

create table Course(
    course# int,
    cname varchar(30),
    dept varchar(30),
    primary key (course#)
);

create table Text(
    book_isbn int,
    booktitle varchar(50),
    publisher varchar(50),
    author varchar(50),
    primary key (book_isbn)
);

create table Enroll(
    regno varchar(20),
    course# int,
    sem int,
    book_isbn int,
    primary key (regno, course#, sem, book_isbn),
    foreign key (regno) references Student on delete cascade,
    foreign key (course#) references Course on delete cascade,
    foreign key (book_isbn) references Text on delete cascade
);

create table Book_Adoption(
    course# int,
    sem int,
    book_isbn int,
    primary key (course#, sem, book_isbn),
    foreign key (course#) references Course on delete cascade,
    foreign key (book_isbn) references Text on delete cascade
);

select table_name from user_table;

insert into Student values ('23012132312321324545', 'Roonil03', 'CSE', '21-Feb-2005');
insert into Student values ('23012132000001367545', 'Griffith', 'ICT', '16-Mar-2004');
insert into Student values ('23011234567890567895', 'Rohit', 'Mechanical', '27-Jun-2005');
insert into Student values ('23098098765432567895', 'Soham', 'DSE','05-Apr-2005');
insert into Student values ('23091117272727272271', 'Hitansh', 'Chemical', '30-Sep-2004');
insert into Student values ('23011234000000000333', 'Rahul', 'ICT','02-Oct-2005');

insert into Course values (1209, 'Data Structures', 'CSE');
insert into Course values (3409, 'Computer Networks', 'ICT');
insert into Course values (1111, 'Thermodynamics', 'Mechanical');
insert into Course values (9088, 'Data Analytics', 'DSE');
insert into Course values (7955, 'Fluid Mechanics', 'Chemical');

insert into Text values (22201010111, 'The Manual to Data Structures', 'Pearson View', 'Lily Harts');
insert into Text values (10201222100, 'Computer Networking', 'Freer Publications', 'Fehraoz Behraz');
insert into Text values (77671727712, 'Heat Transfer and Properties', 'Mechanics Publishers', 'Bob Hotshots');
insert into Text values (12309813342, 'Analysis of Data Patterns', 'Skiena Publications', 'Howard Skiena');
insert into Text values (77782199213, 'Fluid Properties and Mechanics', 'Chemistry is Goated Publishers', 'Ina Skistis');
insert into Text values (99239911234, 'Digital Monsters and Cybersecurity', 'Pearson View', 'Motoaki Hirotaka');
insert into Text values (10010101000, 'Information Security and Networks', 'Pearson View', 'RG Chand');

insert into Enroll values ('23012132312321324545', 1209, 3, 22201010111);
insert into Enroll values ('23012132000001367545', 3409, 4, 10201222100);
insert into Enroll values ('23011234567890567895', 1111, 3, 77671727712);
insert into Enroll values ('23098098765432567895', 9088, 5, 12309813342);
insert into Enroll values ('23091117272727272271', 7955, 4, 77782199213);
insert into Enroll values ('23091117272727272271', 3409, 4, 10201222100);

insert into Book_Adoption values (1209, 3, 22201010111);
insert into Book_Adoption values (3409, 4, 10201222100);
insert into Book_Adoption values (1111, 3, 77671727712);
insert into Book_Adoption values (9088, 5, 12309813342);
insert into Book_Adoption values (7955, 4, 77782199213);
insert into Book_Adoption values (3409, 4, 99239911234);
insert into Book_Adoption values (3409, 4, 10010101000);


select * from Student;

select * from course;

select * from enroll;

select * from Book_Adoption;

select * from Text;