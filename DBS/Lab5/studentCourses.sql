select C.cname, BA.course#, count(distinct BA.book_isbn) as num_books from Book_Adoption BA join Course C on BA.course# = C.course# group by BA.course#, C.cname having count(distinct BA.book_isbn) > 1;
--a

select distinct C.dept from Course C join Book_Adoption BA on C.course# = BA.course# join Text T on BA.book_isbn = T.book_isbn group by C.dept having count(distinct T.publisher) = 1 and MAX(T.publisher) = 'Pearson View';
--b

select S.regno, S.name from Enroll E join Course C on E.course# = C.course# join Student S on E.regno = S.regno group by E.regno, S.regno, S.name having count(distinct C.dept) > 1;
--c

select S.regno, S.name from Student S LEFT join Enroll E on S.regno = E.regno where E.regno IS NULL;
--d

select distinct C.dept from Course C join Book_Adoption BA on C.course# = BA.course# join Text T on BA.book_isbn = T.book_isbn group by C.dept having count(distinct T.publisher) = 1 and MAX(T.publisher) = 'Pearson View';
--e

select distinct T.book_isbn, T.booktitle from Text T join Book_Adoption BA on T.book_isbn = BA.book_isbn join Enroll E on BA.course# = E.course# and BA.sem = E.sem where E.regno = '23091117272727272271'; 
--f

select BA.course# from Book_Adoption BA join Text T on BA.book_isbn = T.book_isbn where T.publisher = 'Pearson View' group by BA.course# having count(distinct BA.book_isbn) >= 2;
--g

select E.regno, S.name, count(distinct E.book_isbn) as num_books from Enroll E join Student S on E.regno = S.regno group by E.regno, S.name having count(distinct E.book_isbn) = (
    select MAX(book_count) 
    from (
        select count(distinct book_isbn) as book_count
        from Enroll
        group by regno
    ) subquery
);
--h

select T.publisher, count(distinct T.book_isbn) as num_books from Text T group by T.publisher;
--i

select E.regno from Enroll E join Course C on E.course# = C.course# join Book_Adoption BA on E.course# = BA.course# and E.sem = BA.sem 
where not exists (
    select 1
    from Book_Adoption BA2
    where BA2.course# = C.course# and BA2.sem = E.sem
    and BA2.book_isbn not in (
        select E2.book_isbn
        from Enroll E2
        where E2.regno = E.regno and E2.course# = C.course# and E2.sem = E.sem
    )
)
group by E.regno;
--j
