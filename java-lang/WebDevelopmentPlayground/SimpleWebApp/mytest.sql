create table USER_ACCOUNT
(
USER_NAME VARCHAR(30) not null,
GENDER    VARCHAR(1) not null,
PASSWORD  VARCHAR(30) not null,
primary key (USER_NAME)
);
 
create table PRODUCT
(
CODE  VARCHAR(20) not null,
NAME  VARCHAR(128) not null,
PRICE FLOAT not null,
primary key (CODE)
) ;
 
insert into USER_ACCOUNT (USER_NAME, GENDER, PASSWORD)
values ('tom', 'M', 'tom001');
 
insert into USER_ACCOUNT (USER_NAME, GENDER, PASSWORD)
values ('jerry', 'M', 'jerry001');
 
insert into PRODUCT (CODE, NAME, PRICE)
values ('P001', 'Java Core', 100);
 
insert into PRODUCT (CODE, NAME, PRICE)
values ('P002', 'C# Core', 90); 
